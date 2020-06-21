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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, TreeNode*> patterns;
        vector<TreeNode*> ans;

        function<string(TreeNode*)> dfs = [&](TreeNode* r) {
            if (!r) return string("#");
            string s = to_string(r->val) + "," + dfs(r->left) + "," + dfs(r->right);
            if (patterns.count(s)) {
                if (patterns[s]) {
                    ans.emplace_back(r);
                    patterns[s] = nullptr;
                }
            } else
                patterns[s] = r;
            return s;
        };

        dfs(root);
        return ans;
    }
};
