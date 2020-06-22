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
    void traverse(TreeNode* root, map<int, int>& rec, int& cnt) {
        if (!root) return;
        rec[root->val]++;
        cnt++;
        traverse(root->left, rec, cnt);
        traverse(root->right, rec, cnt);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        map<int, int> rec;
        int c(0);
        traverse(root1, rec, c);
        traverse(root2, rec, c);
        vector<int> ans(c);

        int k(0);
        auto it = rec.begin();

        while (it != rec.end()) {
            for (int i = 0; i < it->second; ++i)
                ans[k++] = it->first;
            ++it;
        }

        return ans;
    }
};
