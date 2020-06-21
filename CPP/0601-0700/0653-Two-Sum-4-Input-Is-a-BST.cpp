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
    bool findTargetHelper(TreeNode* root, const int& k, unordered_set<int>& record) {
        if (!root) return false;
        if (record.count(k - root->val)) return true;
        record.insert(root->val);
        return findTargetHelper(root->left, k, record) || findTargetHelper(root->right, k, record);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> record;
        return findTargetHelper(root, k, record);
    }
};
