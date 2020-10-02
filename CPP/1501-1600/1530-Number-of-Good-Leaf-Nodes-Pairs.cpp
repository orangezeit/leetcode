class Solution {
public:
    pair<vector<int>, int> dfs(TreeNode* root, int distance) {
        vector<int> depths(distance + 1, 0);
        if (!root->left && !root->right) {
            depths[0] = 1;
            return make_pair(depths, 0);
        }

        vector<int> leftDepths(distance + 1, 0), rightDepths(distance + 1, 0);
        int leftCount = 0, rightCount = 0;
        if (root->left) tie(leftDepths, leftCount) = dfs(root->left, distance);
        if (root->right) {
            tie(rightDepths, rightCount) = dfs(root->right, distance);
        }

        for (int i = 0; i < distance; i++) {
            depths[i + 1] += leftDepths[i];
            depths[i + 1] += rightDepths[i];
        }

        int cnt = 0;
        for (int i = 0; i <= distance; i++) {
            for (int j = 0; j + i + 2 <= distance; j++) {
                cnt += (leftDepths[i] * rightDepths[j]);
            }
        }
        return make_pair(depths, cnt + leftCount + rightCount);
    }

    int countPairs(TreeNode* root, int distance) {
        return dfs(root, distance).second;
    }
};
