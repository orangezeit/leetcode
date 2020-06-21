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
    void record(TreeNode* root, int& prev, int& dist) {
        if (!root) return;
        record(root->left, prev, dist);
        if (prev != INT_MAX)
            dist = min(dist, root->val - prev);
        prev = root->val;
        record(root->right, prev, dist);
    }

    int minDiffInBST(TreeNode* root) {
        int prev(INT_MAX), dist(INT_MAX);
        record(root, prev, dist);

        return dist;
    }
};
