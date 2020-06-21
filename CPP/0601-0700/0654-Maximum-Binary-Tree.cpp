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
    TreeNode* buildTree (vector<int>& nums, int l, int r) {
        // recursion method

        if (l == r) return nullptr;

        int max = nums[l];
        int index = l;

        for (int i = l; i < r; ++i) {
            if (max < nums[i]) {
                max = nums[i];
                index = i;
            }
        }

        TreeNode* MBT = new TreeNode(max);
        MBT->left = buildTree(nums, l, index);
        MBT->right = buildTree(nums, index+1, r);

        return MBT;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size());
    }
};
