class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.emplace_back(n);
        n = cuts.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 0;
        for (int c = 2; c <= n; ++c)
            for (int i = 0, j = i + c - 1; j < n; ++i, ++j)
                for (int k = i; k < j; ++k)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cuts[j] - (i ? cuts[i - 1] : 0));
        return dp[0][n - 1];
    }
};
