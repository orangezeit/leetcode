class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.length();
        vector<vector<int>> dp(len + 2, vector<int>(len + 2));

        for (int l = 1; l <= len; ++l) {
            for (int i = 1; i + l - 1 <= len; ++i) {
                int j = i + l - 1;
                dp[i][j] = s[i-1] == s[j-1] ? dp[i+1][j-1] + (i == j ? 1 : 2) : max(dp[i+1][j], dp[i][j-1]);
            }
        }

        return dp[1][len];
    }
};
