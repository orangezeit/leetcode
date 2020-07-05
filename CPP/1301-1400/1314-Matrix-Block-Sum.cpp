class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m(mat.size()), n(mat[0].size());
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int x = -K; x <= K; ++x) {
                    for (int y = -K; y <= K; ++y) {
                        if (i + x < 0 || i + x >= m || j + y < 0 || j + y >= n) continue;
                        ans[i][j] += mat[i + x][j + y];
                    }
                }
            }
        }
        return ans;
    }
};
