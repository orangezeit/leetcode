class Solution {
public:
    int mf(const int& a, const int& b, const int& c, const int& d) {
        return max(a, max(b, max(c, d)));
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n(grid.size()), dp[n][n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    dp[i][j][k] = INT_MIN;
        dp[0][0][0] = grid[0][0];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = max(0, i + j - n + 1); k < min(i + j + 1, n); ++k) {
                    if (grid[i][j] == -1 || grid[k][i+j-k] == -1) continue;
                    int prev = mf(i ? dp[i-1][j][k] : INT_MIN, j ? dp[i][j-1][k] : INT_MIN,
                                  i && k ? dp[i-1][j][k-1] : INT_MIN, j && k ? dp[i][j-1][k-1] : INT_MIN);
                    if (prev < 0) continue;
                    dp[i][j][k] = prev + grid[i][j] + (i == k ? 0 : grid[k][i+j-k]);
                }

        return max(0, dp[n-1][n-1][n-1]);
    }
};
