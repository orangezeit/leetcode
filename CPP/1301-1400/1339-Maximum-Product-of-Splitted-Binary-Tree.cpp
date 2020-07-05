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
    long add(TreeNode* root) {
        if (!root) return 0;
        root->val += add(root->left) + add(root->right);
        return root->val;
    }
    void traverse(TreeNode* root, long long& mp, const long& total) {
        if (!root) return;
        mp = max(mp, (long long)root->val * (total - root->val));
        traverse(root->left, mp, total);
        traverse(root->right, mp, total);
    }
    int maxProduct(TreeNode* root) {
        long total = add(root);
        long long mp(0);
        traverse(root, mp, total);
        return (mp % 1000000007);
    }
};
