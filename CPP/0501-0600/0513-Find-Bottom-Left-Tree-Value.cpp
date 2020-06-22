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
    void BLN(TreeNode* root, pair<int,int>& target, int level) {
        if (!root) return;
        if (level > target.second) target = {root->val, level};
        BLN(root->left, target, level+1);
        BLN(root->right, target, level+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        pair<int, int> target(root->val, 0);
        BLN(root, target, 0);
        return target.first;
    }
};
