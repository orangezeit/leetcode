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
    // {smallest, largest, curr_sum}
    vector<int> traverse(TreeNode* root, int& ans, bool bk) {
        if (!root) return {INT_MAX, INT_MIN, 0};
        if (!bk) return {};
        vector<int> left(traverse(root->left, ans, bk)), right(traverse(root->right, ans, bk));
        if (left.empty() || right.empty() || root->val <= left[1] || root->val >= right[0]) {
            bk = false;
            return {};
        }
        int curr_sum = left[2] + right[2] + root->val;
        ans = max(ans, curr_sum);
        return {min(left[0], root->val), max(right[1], root->val), curr_sum};
    }
    int maxSumBST(TreeNode* root) {
        int ans(0);
        bool bk(true);
        traverse(root, ans, bk);
        return max(0, ans);
    }
};
