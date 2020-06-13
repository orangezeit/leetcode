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
    void walkthrough(TreeNode* root, int& lower, int& upper, double target) {
        if (!root)
            return;

        if (root->val > target) {
            upper = min(upper, root->val);
            walkthrough(root->left, lower, upper, target);
        } else {
            lower = max(lower, root->val);
            walkthrough(root->right, lower, upper, target);
        }
    }

    int closestValue(TreeNode* root, double target) {
        int lower(INT_MIN), upper(INT_MAX);

        walkthrough(root, lower, upper, target);
        if (lower == INT_MIN)
            return upper;
        if (upper == INT_MAX)
            return lower;
        return 2 * target < upper + lower ? lower : upper;
    }
};
