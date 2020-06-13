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
    pair<int, int> traverse(TreeNode* root, double& max_average) {
        if (root == nullptr) return {0, 0};

        int sum = root->val;
        int cnt = 1;

        pair<int, int> p1 = traverse(root->left, max_average);
        pair<int, int> p2 = traverse(root->right, max_average);

        sum += p1.first + p2.first;
        cnt += p1.second + p2.second;
        //cout << sum << " " << cnt << endl;
        max_average = max(max_average, sum * 1.0 / cnt);

        return {sum, cnt};

    }
    double maximumAverageSubtree(TreeNode* root) {
        double max_average = 0.0;
        traverse(root, max_average);
        return max_average;
    }
};
