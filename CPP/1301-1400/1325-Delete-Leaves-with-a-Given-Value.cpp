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
    void traverse(TreeNode* root, const int target) {
        if (!root) return;
        traverse(root->left, target);
        traverse(root->right, target);
        bool erased = true;
        if (root->left && root->left->val != -1) erased = false;
        if (root->right && root->right->val != -1) erased = false;
        if (erased && root->val == target) root->val = -1;

    }
    TreeNode* remove(TreeNode* root) {
        if (!root) return NULL;
        if (root->val == -1) return NULL;
        root->left = remove(root->left);
        root->right = remove(root->right);
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        traverse(root, target);
        return remove(root);
    }
};
