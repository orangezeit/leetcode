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
    int maxVal;
    pair<int, int> traverse(TreeNode* root) {
        if (!root) return {0, 0};
        int inr = 1, dcr = 1;

        if (root->left) {
            pair<int, int> p1 = traverse(root->left);
            if (root->val - root->left->val == 1)
                dcr = p1.second + 1;
            if (root->val - root->left->val == -1)
                inr = p1.first + 1;
        }

        if (root->right) {
            pair<int, int> p2 = traverse(root->right);
            if (root->val - root->right->val == 1)
                dcr = max(dcr, p2.second + 1);
            if (root->val - root->right->val == -1)
                inr = max(inr, p2.first + 1);
        }
        maxVal = max(maxVal, dcr + inr - 1);
        return {inr, dcr};
    }
    int longestConsecutive(TreeNode* root) {
        traverse(root);
        return maxVal;
    }
};
