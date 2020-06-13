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
    vector<TreeNode*> splitBST(TreeNode* root, int v) {
        if (!root)
            return {nullptr, nullptr};
        else if (root->val > v) {
            vector<TreeNode*> ans = splitBST(root->left, v);
            root->left = ans[1];
            ans[1] = root;
            return ans;
        } else {
            vector<TreeNode*> ans = splitBST(root->right, v);
            root->right = ans[0];
            ans[0] = root;
            return ans;
        }
    }
};
