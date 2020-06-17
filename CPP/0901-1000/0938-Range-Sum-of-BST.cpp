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
    int rangeSumBST(TreeNode* root, const int& L, const int& R) {
        return root ? (root->val >= L && root->val <= R ? root->val : 0) + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) : 0;
    }
};
