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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans(nullptr);
        function<void(TreeNode*, TreeNode*)> dfs = [&](TreeNode* o, TreeNode* c) {
            if (!o || ans) return;
            if (o == target) {
                ans = c;
                return;
            }
            dfs(o->left, c->left);
            dfs(o->right, c->right);
        };
        dfs(original, cloned);
        return ans;
    }
};
