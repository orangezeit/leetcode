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
    bool helper(TreeNode* root, const int& val) {
        if (root == NULL) return true;

        return root->val == val && helper(root->left, val) && helper(root->right, val);
    }

    bool isUnivalTree(TreeNode* root) {
        return (!root->left || root->left->val == root->val && isUnivalTree(root->left)) &&
               (!root->right || root->right->val == root->val && isUnivalTree(root->right));
    }
};
