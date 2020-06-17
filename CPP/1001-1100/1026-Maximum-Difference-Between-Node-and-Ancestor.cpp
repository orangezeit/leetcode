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
    void traverseMaxDiff(TreeNode* root, int minVal, int maxVal, int& maxDiff) {
        //cout << minVal << " " << maxVal << endl;
        if (!root) {
            maxDiff = max(maxDiff, maxVal - minVal);
            return;
        }
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);
        traverseMaxDiff(root->left, minVal, maxVal, maxDiff);
        traverseMaxDiff(root->right, minVal, maxVal, maxDiff);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff(0);
        traverseMaxDiff(root, 100001, -1, maxDiff);
        return maxDiff;
    }
};
