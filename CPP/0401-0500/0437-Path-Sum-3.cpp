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
    void traverse(TreeNode* root, const int& sum, int s, int& c) {
        if (!root) return;
        s += root->val;
        c += (s == sum);
        traverse(root->left, sum, s, c);
        traverse(root->right, sum, s, c);
    }
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int c = 0;
        traverse(root, sum, 0, c);
        return c + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};
