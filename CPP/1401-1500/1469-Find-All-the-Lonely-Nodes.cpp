/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* root, vector<int>& ans) {
        if (root->left) {
            if (!root->right) ans.push_back(root->left->val);
            traverse(root->left, ans);
        }

        if (root->right) {
            if (!root->left) ans.push_back(root->right->val);
            traverse(root->right, ans);
        }
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};
