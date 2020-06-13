class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length()));

        for (int len = 1; len <= s.length(); ++len) {
            for (int i = 0; i + len - 1 < s.length(); ++i) {
                int j = i + len - 1;
                dp[i][j] = s[i] == s[j] ? len > 2 ? dp[i+1][j-1] + 2 : j - i + 1 : max(dp[i][j-1], dp[i+1][j]);
            }
        }
        //cout << dp[0][s.length() - 1] << endl;
        return dp[0][s.length() - 1] + k >= s.length();
    }
};
