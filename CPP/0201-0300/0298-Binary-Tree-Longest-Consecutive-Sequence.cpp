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
    int traverse(TreeNode* root, TreeNode* parent, int len) {
        if (!root) return len;
        len = parent && root->val - 1 == parent->val ? len + 1 : 1;

        return  max(len, max(traverse(root->left, root, len), traverse(root->right, root, len)));
    }
    int longestConsecutive(TreeNode* root) {
        return traverse(root, NULL, 0);
    }
};
