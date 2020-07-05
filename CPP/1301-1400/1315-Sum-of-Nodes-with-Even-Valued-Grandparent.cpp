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
    void findSum(TreeNode* root, int& s, int p, int gp) {
        if (!root) return;
        if (gp == 1) s += root->val;
        findSum(root->left, s, !(root->val % 2), p);
        findSum(root->right, s, !(root->val % 2), p);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int s(0);
        findSum(root, s, -1, -1);
        return s;
    }
};
