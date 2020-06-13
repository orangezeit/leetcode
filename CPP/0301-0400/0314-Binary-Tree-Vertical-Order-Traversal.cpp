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
    map<int, vector<vector<int>>> record;

    void helper(TreeNode* root, int n, int level) {
        if (root == NULL)
            return;

        while (record[n].size() <= level) {
            record[n].push_back({});
        }

        record[n][level].push_back(root->val);
        helper(root->left, n - 1, level + 1);

        helper(root->right, n + 1, level + 1);
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(root, 0, 0);

        for (auto it = record.begin(); it != record.end(); ++it) {
            vector<int> temp;

            for (int k = 0; k < it->second.size(); ++k)
                if (!it->second[k].empty())
                    temp.insert(temp.end(), it->second[k].begin(), it->second[k].end());

            ans.push_back(temp);
        }

        return ans;
    }
};
