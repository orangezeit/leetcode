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
    map<int, vector<pair<int, int>>> pos;
public:
    void helper(TreeNode* root, int X, int Y) {
        if (!root) return;
        pos[X].push_back({Y, root->val});
        helper(root->left, X-1, Y+1);
        helper(root->right, X+1, Y+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root, 0, 0);

        vector<vector<int>> ans(pos.size());
        int i = -1;

        for (auto& [k, v]: pos) {
            ans[++i].resize(v.size());
            sort(v.begin(), v.end());
            for (int j = 0; j < v.size(); ++j) {
                ans[i][j] = v[j].second;
            }
        }

        return ans;
    }
};
