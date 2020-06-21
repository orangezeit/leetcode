class Solution {
public:
    int numDecodings(string s) {
        int mod(1e9+7);
        long dp[s.length() + 1] = {};
        dp[0] = 1;
        dp[1] = s[0] == '*' ? 9 : s[0] != '0';

        for (int i = 2; i <= s.length(); ++i) {
            dp[i] += s[i-1] == '*' ? dp[i-1] * 9 : s[i-1] == '0' ? 0 : dp[i-1];
            if (s[i-1] == '*' && s[i-2] == '*') {
                dp[i] += dp[i-2] * 15;
            } else if (s[i-1] == '*') {
                dp[i] += dp[i-2] * (s[i-2] == '1' ? 9 : s[i-2] == '2' ? 6 : 0);
            } else if (s[i-2] == '*') {
                dp[i] += dp[i-2] * (s[i-1] <= '6' ? 2 : 1);
            } else {
                dp[i] += s[i-2] == '1' || s[i-2] == '2' && s[i-1] <= '6' ? dp[i-2] : 0;
            }
            dp[i] %= mod;
        }

        return dp[s.length()];
    }
};
