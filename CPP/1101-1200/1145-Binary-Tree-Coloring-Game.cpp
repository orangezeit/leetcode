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
private:
    int l, r;
    int countNodes(TreeNode* root, int x) {
        if (!root) return 0;
        int left = countNodes(root->left, x);
        int right = countNodes(root->right, x);
        if (root->val == x) {
            l = left;
            r = right;
        }
        return left + right + 1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        countNodes(root, x);
        return max(n - l - r - 1, max(l, r)) > n / 2;
    }
};
