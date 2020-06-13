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
    bool helper2(TreeNode* root, const int& val) {
        if (!root) return false;
        if (root->val == val) return true;
        return root->val > val ? helper2(root->left, val) : helper2(root->right, val);
    }

    bool helper(TreeNode* root1, TreeNode* root2, const int& target) {
        if (!root1) return false;
        bool found(false);
        int remain(target - root1->val);
        return helper2(root2, remain) || helper(root1->left, root2, target) || helper(root1->right, root2, target);
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        return helper(root1, root2, target);
    }
};
