class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m(matrix.size()), n(matrix[0].size()), ans(0);
        vector<vector<int>> preSums(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                preSums[i][j] += matrix[i-1][j-1] + preSums[i-1][j] + preSums[i][j-1] - preSums[i-1][j-1];
            }
        }

        for (int k = 1; k <= min(m, n); ++k) {
            for (int i = k; i <= m; ++i) {
                for (int j = k; j <= n; ++j) {
                    if (preSums[i][j] -preSums[i][j-k]-preSums[i-k][j] + preSums[i-k][j-k] == k * k) ans++;
                }
            }
        }

        return ans;
    }
};
