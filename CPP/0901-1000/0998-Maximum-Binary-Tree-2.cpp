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
    void inorderHelper(TreeNode* root, vector<int>& vals) {
        if (root) {
            inorderHelper(root->left, vals);
            vals.push_back(root->val);
            inorderHelper(root->right, vals);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vals;
        inorderHelper(root, vals);
        return vals;
    }

    TreeNode* buildTree (const vector<int>& nums, int l, int r) {
        if (l == r) return NULL;

        int maxNum = nums[l];
        int index = l;

        for (int i = l + 1; i < r; ++i) {
            if (maxNum < nums[i]) {
                maxNum = nums[i];
                index = i;
            }
        }

        TreeNode* t = new TreeNode(maxNum);
        t->left = buildTree(nums, l, index);
        t->right = buildTree(nums, index+1, r);
        return t;
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> vals = inorderTraversal(root);
        vals.push_back(val);
        return buildTree(vals, 0, vals.size());
    }
};
