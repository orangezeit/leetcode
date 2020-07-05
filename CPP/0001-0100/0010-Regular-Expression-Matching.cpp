class Solution {
public:
    bool isMatch(string s, string p) {
        // Time Complexity: O(M + N)
        // Space Complexity: O(MN)
        const int m(s.length()), n(p.length());
        int dp[m + 1][n + 1] = {};

        dp[0][0] = 1;
        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j-1] == '*') {
                    dp[i][j] |= dp[i][j-2];
                    int k(i);
                    while (--k >= 0 && (p[j-2] == '.' || s[k] == p[j-2]))
                        dp[i][j] |= dp[k][j-2];
                }
                if (i && (s[i-1] == p[j-1] || p[j-1] == '.'))
                    dp[i][j] |= dp[i-1][j-1];

            }
        }

        return dp[m][n];
    }
};
