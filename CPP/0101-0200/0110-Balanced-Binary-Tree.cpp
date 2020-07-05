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
    int balanceHelper(TreeNode* root) {
        if (!root) return 0;
        int left(balanceHelper(root->left)), right(balanceHelper(root->right));
        if (left == -1 || right == -1 || abs(left-right) > 1) return -1;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return balanceHelper(root) != -1;
    }
};
