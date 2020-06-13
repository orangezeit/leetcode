/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<int>> rec;
    int head;

    void build_map(TreeNode* root) {
        if (root->left) {
            rec[root->val].push_back(root->left->val);
            rec[root->left->val].push_back(root->val);
            build_map(root->left);
        }

        if (root->right) {
            rec[root->val].push_back(root->right->val);
            rec[root->right->val].push_back(root->val);
            build_map(root->right);
        }
    }

    void traverse(int curr, unordered_set<int> steps, int& len, int& ans) {
        if (rec[curr].size() == 1 && curr != head) {
            if (len > steps.size()) {
                len = steps.size();
                ans = curr;
            }
        } else {
            for (int i = 0; i < rec[curr].size(); ++i) {
                if (steps.find(curr) == steps.end()) {
                    steps.insert(curr);
                    traverse(rec[curr][i], steps, len, ans);
                    steps.erase(curr);
                }
            }
        }
    }

    int findClosestLeaf(TreeNode* root, int k) {
        head = root->val;
        int ans(root->val), len(1000);
        unordered_set<int> steps;
        build_map(root);
        traverse(k, steps, len, ans);
        return ans;
    }
};
