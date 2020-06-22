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
    pair<int, int> helper(TreeNode* root) {
        if (!root) return {0, 0};
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        return {root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second)};

    }
    int rob(TreeNode* root) {
        pair<int, int> ans = helper(root);
        return max(ans.first, ans.second);
    }
};
