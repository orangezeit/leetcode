class Solution {
public:
    int kInversePairs(const int n, const int k) {
        vector<vector<long>> dp(n + 1, vector<long>(k + 1));
        const int M(1e9+7);
        for (int i = 0; i <= n; ++i)
            dp[i][0] = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
                dp[i][j] = (dp[i][j-1] + dp[i-1][j] - (i <= j ? dp[i-1][j-i] : 0) + M) % M;
        return dp[n][k];
    }
};
