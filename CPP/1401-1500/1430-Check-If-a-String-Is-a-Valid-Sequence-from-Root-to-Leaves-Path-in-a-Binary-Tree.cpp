/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidSequence(TreeNode* root, const vector<int>& arr, int i=0) {
        return !root || i == arr.size() ? !root && i == arr.size() : arr[i] == root->val &&
               (isValidSequence(root->left, arr, i + 1) || isValidSequence(root->right, arr, i + 1)) &&
               (i + 1 == arr.size() ? !root->left && !root->right : true);
    }
};
