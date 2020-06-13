class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1));

        dp[0][0] = 1;
        for (int i = 0; i <= s.length(); ++i) {
            for (int j = 1; j <= p.length(); ++j) {
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

        return dp.back().back();
    }
};
