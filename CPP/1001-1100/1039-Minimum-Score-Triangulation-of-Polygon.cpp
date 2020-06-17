class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX/3));

        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                for (int k = i + 1; k <= j - 1; ++k) {
                    dp[i][j] = min(dp[i][j], (k - i == 1 ? 0 : dp[i][k]) + A[i] * A[j] * A[k] + (j - k == 1 ? 0 : dp[k][j]));
                }
            }
        }

        return dp[0][n-1];
    }
};
