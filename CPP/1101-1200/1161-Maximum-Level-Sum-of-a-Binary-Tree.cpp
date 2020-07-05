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
private:
    vector<int> levels;
    queue<pair<TreeNode*, int>> q;
public:
    int maxLevelSum(TreeNode* root) {
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* tn = q.front().first;
            int level = q.front().second;
            q.pop();

            if (level == levels.size())
                levels.push_back(0);
            levels[level] += tn->val;
            if (tn->left) q.push({tn->left, level+1});
            if (tn->right) q.push({tn->right, level+1});
        }
        int ans(INT_MIN), idx(0);
        for (int i = 0; i < levels.size(); ++i)
            if (levels[i] > ans) {
                ans = levels[i];
                idx = i;
            }
        return idx + 1;
    }
};
