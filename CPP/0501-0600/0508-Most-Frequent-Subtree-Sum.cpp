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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> record;
        int mx = 0;
        vector<int> res;

        function<int(TreeNode*)> dfs = [&](TreeNode* r) {
            if (!r) return 0;
            mx = max(mx, ++record[r->val += dfs(r->left) + dfs(r->right)]);
            return r->val;
        };

        dfs(root);

        for (const auto& [k, v]: record)
            if (v == mx)
                res.emplace_back(k);

        return res;
    }
};
