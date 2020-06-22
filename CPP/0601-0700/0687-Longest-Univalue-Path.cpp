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
    int uniPath(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;

        int l = uniPath(root->left, ans);
        int r = uniPath(root->right, ans);
        int pl(0), pr(0);

        if (root->left)
            if (root->left->val == root->val)
                pl = l + 1;

        if (root->right)
            if (root->right->val == root->val)
                pr = r + 1;

        ans = max(ans, pl + pr);

        return max(pl, pr);
    }

    int longestUnivaluePath(TreeNode* root) {
        int longest = 0;

        uniPath(root, longest);

        return longest;
    }
};
