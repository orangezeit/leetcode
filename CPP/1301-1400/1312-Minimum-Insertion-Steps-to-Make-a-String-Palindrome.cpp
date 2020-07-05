class Solution {
public:
    int minInsertions(string s) {
        int n(s.length()), dp[n][n] = {};
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[0][n - 1];
    }
};
