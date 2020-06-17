/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
private:
    TreeNode* t;
    vector<int> id;

    vector<int> path(int k) {
        vector<int> ans = id;
        int twos = pow(2, ans.size() - 1);

        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = k / twos;
            k -= ans[i] * twos;
            twos /= 2;
        }
        return ans;
    }

    bool track(int k) {
        vector<int> p = path(k);

        TreeNode* temp = t;

        for (int i = 0; i < p.size(); ++i) {
            p[i] ? temp = temp->right : temp = temp->left;
        }

        return temp == NULL;
    }

public:

    CBTInserter(TreeNode* root) {
        t = root;

        int balance = 0;
        TreeNode* l = root;
        TreeNode* r = root;

        while (l->left) {
            l = l->left;
            balance++;
        }

        int level = balance;
        id = vector<int>(level, 0);

        while (r->right) {
            r = r->right;
            balance--;
        }

        if (balance) {

            int i = 0;
            int j = pow(2, level) - 1;

            while (i < j) {
                int m = (i+j) / 2;

                if (track(m)) {
                    j = m;
                } else {
                    if (track(m+1)) {
                        id = path(m + 1);
                        break;
                    } else {
                        i = m;
                    }
                }
            }
        } else {
            id.push_back(0);
        }
    }

    int insert(int v) {
        TreeNode* temp = t;

        for (int i = 0; i < id.size() - 1; ++i) {
            id[i] ? temp = temp->right : temp = temp->left;
        }

        id.back() ? temp->right = new TreeNode(v) : temp->left = new TreeNode(v);

        for (int i = id.size() - 1; i >= 0; --i) {
            if (id[i] == 0) {
                id[i] = 1;
                return temp->val;
            } else {
                id[i] = 0;
            }
        }

        id.push_back(0);
        return temp->val;
    }

    TreeNode* get_root() {
        return t;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
