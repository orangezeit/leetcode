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
    void helper(TreeNode* root, const vector<int>& voyage, int& pos, vector<int>& ans) {
        if (!root) return;
        if (!ans.empty() && ans[0] == -1) return;
        if (root->val != voyage.at(pos)) {
            ans = {-1};
            return;
        }

        if (root->left && root->left->val != voyage.at(pos+1)) {
            swap(root->left, root->right);
            ans.push_back(root->val);
        }
        ++pos;
        helper(root->left, voyage, pos, ans);
        helper(root->right, voyage, pos, ans);
    }

    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        int pos(0);
        vector<int> ans;
        helper(root, voyage, pos, ans);
        return ans;
    }
};
