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
    void helper(TreeNode* root, string& str, string& ans) {
        if (!root) return;
        str += 'a' + root->val;
        if (!root->left && !root->right) {
            reverse(str.begin(), str.end());
            ans = min(ans, str);
            reverse(str.begin(), str.end());
        }
        helper(root->left, str, ans);
        helper(root->right, str, ans);
        str.pop_back();
    }

    string smallestFromLeaf(TreeNode* root) {
        string s, ans("{");
        helper(root, s, ans);
        return ans;
    }
};
