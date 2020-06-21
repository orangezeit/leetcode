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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> vals;

        vector<int> counts;

        function<void()> dfs = [&](TreeNode* r, int level) {
            if (!r) return;
            if (level == vals.size()) {
                vals.emplace_back(r->val);
                counts.emplace_back(1);
            } else {
                vals[level] += r->val;
                counts[level]++;
            }
            dfs(r->left, level + 1);
            dfs(r->right, level + 1);
        };

        dfs(root, 0);

        for (int i = 0; i < vals.size(); ++i)
            vals[i] /= counts[i];

        return vals;
    }
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q({root});
        vector<double> ans;
        while (!q.empty()) {
            int s = q.size();
            double total = 0.0;
            for (int i = 0; i < s; ++i) {
                TreeNode* r = q.front();
                q.pop();
                total += r->val;
                if (r->left) q.push(r->left);
                if (r->right) q.push(r->right);
            }
            ans.emplace_back(total / s);
        }
        return ans;
    }
};
