class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        for (int i = 1; i < text1.length() + 1; ++i)
            for (int j = 1; j < text2.length() + 1; ++j)
                dp[i][j] = text1[i - 1] == text2[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);

        return dp.back().back();
    }
};
