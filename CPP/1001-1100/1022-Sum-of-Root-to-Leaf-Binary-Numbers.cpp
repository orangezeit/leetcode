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
    int sumRootToLeaf(TreeNode* root, string num="") {
        if (!root) return 0;
        num += '0' + root->val;
        if (!root->left && !root->right) return stoi(num, 0, 2);
        return sumRootToLeaf(root->left, num) + sumRootToLeaf(root->right, num);
    }
};
