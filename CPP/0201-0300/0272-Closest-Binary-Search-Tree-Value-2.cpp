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
    vector<int> findClosestElements(vector<int>& arr, int k, double x) {
        if (x <= arr[0]) {
            arr.resize(k);
            return arr;
        }

        int i = 0;
        int j = arr.size() - 1;

        while (j - i > 1) {
            int m = (i + j) / 2;
            arr[m] <= x ? i = m : j = m;
        }

        if (2 * x > arr[i] + arr[j]) i = j;
        int left = -1;
        int right = 1;

        while (--k)
            i + left < 0 ? right++ : i + right == arr.size() ? left-- : 2 * x <= arr[i + left] + arr[i + right] ? left-- : right++;

        return vector<int>(arr.begin() + i + left + 1, arr.begin() + i + right);
    }
    void traverse(TreeNode* root, vector<int>& inorder) {
        if (!root) return;
        traverse(root->left, inorder);
        inorder.push_back(root->val);
        traverse(root->right, inorder);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> inorder;
        traverse(root, inorder);
        return findClosestElements(inorder, k, target);
    }
};
