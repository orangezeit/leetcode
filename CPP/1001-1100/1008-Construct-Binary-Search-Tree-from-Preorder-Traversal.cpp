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
    TreeNode* bstFromPreorderHelper(const vector<int>& preorder, int left, int right) {
        if (left == right) return NULL;

        TreeNode* t = new TreeNode(preorder[left]);

        for (int i = left + 1; i < right; ++i) {
            if (preorder[i] > preorder[left]) {
                t->left = bstFromPreorderHelper(preorder, left + 1, i);
                t->right = bstFromPreorderHelper(preorder, i, right);
                return t;
            }
        }

        t->left = bstFromPreorderHelper(preorder, left + 1, right);
        return t;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bstFromPreorderHelper(preorder, 0, preorder.size());
    }
};
