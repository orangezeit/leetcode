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
    int traverseToMeasure(TreeNode* root, int& d) {
        if (!root)
            return -1;

        int left(traverseToMeasure(root->left, d) + 1), right(traverseToMeasure(root->right, d) + 1);
        d = max(d, left + right);
        return max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diameter(0);
        traverseToMeasure(root, diameter);
        return diameter;
    }
};
