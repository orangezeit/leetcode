class Solution {
public:
    bool isMatch(string s, string p) {
        // Time Complexity: O(MN)
        // Space Complexity: O(N)
        int m(s.length()), n(p.length());
        bool dp[2][n + 1] = {}, matches[n + 1] = {};
        matches[0] = dp[0][0] = true;

        for (int j = 1; j <= n && p[j - 1] == '*'; ++j)
            matches[j] = dp[0][j] = true;

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = matches[j - 1];
                }
                matches[j] |= dp[i][j];
            }
        return dp[m % 2][n];
    }
};
