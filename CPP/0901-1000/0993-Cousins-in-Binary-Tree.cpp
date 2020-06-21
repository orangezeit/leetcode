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
    void traverseToFindCousin(TreeNode* root, const int& target, int parent, int level, vector<int>& record) {
        if (!root) return;

        if (root->val == target) {
            record[0] = parent;
            record[1] = level;
            return;
        }

        traverseToFindCousin(root->left, target, root->val, level+1, record);
        traverseToFindCousin(root->right, target, root->val, level+1, record);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        vector<int> dx(2, -1), dy(2, -1);
        traverseToFindCousin(root, x, 0, 0, dx);
        traverseToFindCousin(root, y, 0, 0, dy);

        return dx[0] != dy[0] && dx[1] == dy[1];
    }
};
