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
    void findDeep(TreeNode* root, int level, int& maxLevel, int& s) {
        if (!root) return;
        if (level > maxLevel) {
            maxLevel = level;
            s = root->val;
        } else if (level == maxLevel) {
            s += root->val;
        }
        findDeep(root->left, level + 1, maxLevel, s);
        findDeep(root->right, level + 1, maxLevel, s);
    }
    int deepestLeavesSum(TreeNode* root) {
        int s(0), maxLevel(0);
        findDeep(root, 0, maxLevel, s);
        return s;
    }
};
