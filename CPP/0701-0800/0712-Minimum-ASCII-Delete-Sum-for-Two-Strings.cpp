class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));

        for (int i = 1; i <= s1.length(); ++i) dp[i][0] = dp[i-1][0] + s1[i-1];
        for (int i = 1; i <= s2.length(); ++i) dp[0][i] = dp[0][i-1] + s2[i-1];
        for (int i = 1; i <= s1.length(); ++i)
            for (int j = 1; j <= s2.length(); ++j)
                dp[i][j] = s1[i - 1] == s2[j - 1] ? dp[i - 1][j - 1] : min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);

        return dp.back().back();
    }
};
