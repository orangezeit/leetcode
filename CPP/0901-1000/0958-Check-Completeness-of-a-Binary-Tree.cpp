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
    void record(TreeNode* root, int& nodes, int index, int& maxIndex) {
        if (!root || maxIndex == -1) return;
        nodes++;
        maxIndex = max(index, maxIndex);
        if (maxIndex > 100) return;
        record(root->left, nodes, index * 2, maxIndex);
        record(root->right, nodes, index * 2 + 1, maxIndex);
    }

    bool isCompleteTree(TreeNode* root) {
        int nodes(0), maxIndex(1);
        record(root, nodes, 1, maxIndex);
        return nodes == maxIndex;
    }
};
