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
    vector<int> traverseBST(TreeNode* root) {
        if (!root) return {1, 0, INT_MIN, INT_MAX};
        if (!root->left && !root->right) return {1, 1, root->val, root->val};

        vector<int> left = traverseBST(root->left);
        vector<int> right = traverseBST(root->right);

        if (left[0] && right[0]) {

            if (left[2] == INT_MIN && root->val < right[2]) {
                left[2] = root->val;
                left[3] = root->val;
            } else if (right[3] == INT_MAX && root->val > left[3]) {
                right[2] = root->val;
                right[3] = root->val;
            }

            if (root->val <= right[2] && root->val >= left[3])
                return {1, 1 + left[1] + right[1], left[2], right[3]};
        }

        return {0, max(left[1], right[1]), 0, 0};
    }

    int largestBSTSubtree(TreeNode* root) {
        return traverseBST(root)[1];
    }
};
