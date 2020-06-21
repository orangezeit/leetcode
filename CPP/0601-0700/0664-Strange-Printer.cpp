class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length(), dp[n][n] = {};
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = (j ? dp[i][j - 1] : 0) + 1;
                for (int k = i; k < j; ++k)
                    if (s[k] == s[j])
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
            }
        }
        return n ? dp[0][n - 1] : 0;
    }
};
