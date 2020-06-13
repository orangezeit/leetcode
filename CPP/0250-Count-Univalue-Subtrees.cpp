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
    bool isUnivalTree(TreeNode* root) {
        return (!root->left || root->left->val == root->val && isUnivalTree(root->left)) &&
           (!root->right || root->right->val == root->val && isUnivalTree(root->right));
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        return root ? isUnivalTree(root) + countUnivalSubtrees(root->left) + countUnivalSubtrees(root->right) : 0;
    }
};
