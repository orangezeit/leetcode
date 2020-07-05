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
private:
    int len = 0;
    vector<TreeNode*> ans;
public:
    void compare(vector<TreeNode*> b) {
        for (int i = 0; i < ans.size(); ++i)
            if (ans[i] != b[i]) {
                ans.resize(i);
                return;
            }
    }

    void traverse(TreeNode* root, vector<TreeNode*>& branch) {

        if (!root) {
            if (branch.size() > len) {
                len = branch.size();
                ans = branch;
            } else if (branch.size() == len)
                compare(branch);
            return;
        }
        branch.push_back(root);
        traverse(root->left, branch);
        if (root->left || root->right) traverse(root->right, branch);
        branch.pop_back();
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        vector<TreeNode*> branch;
        traverse(root, branch);
        return ans.back();
    }
};
