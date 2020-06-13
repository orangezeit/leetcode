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
    void orderHelper(TreeNode* root, vector<TreeNode*>& vals) {
        if (!root) return;
        orderHelper(root->left, vals);
        vals.push_back(root);
        orderHelper(root->right, vals);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> vals;
        orderHelper(root, vals);
        vals.push_back(nullptr);
        for (int i = 0; i < vals.size(); ++i) {
            if (p == vals[i]) return vals[i+1];
        }
        return NULL;
    }
};
