class Solution {
public:
    int maxPathSumHelper(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        int maxLeft = max(maxPathSumHelper(root->left, maxSum), 0);
        int maxRight = max(maxPathSumHelper(root->right, maxSum), 0);
        maxSum = max(maxSum, root->val + maxLeft + maxRight);
        return max(maxLeft, maxRight) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum(INT_MIN);
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
};
