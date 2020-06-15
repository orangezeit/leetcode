class Solution {
public:
    int numberOfArrays(string s, int k) {
        string sk = to_string(k);
        int n(s.length()), m(sk.length()), mod(1e9+7);
        // k: up to 10 digits
        vector<long> dp(n + 1);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            string t;
            for (int j = 0; j < min(m, n - i); ++j) {
                t += s[i + j];
                if (j == m - 1 && t > sk) break;
                if (i + j + 1 == n || s[i + j + 1] != '0')
                    dp[i] += dp[i + j + 1];
            }
            dp[i] %= mod;
        }
        return dp[0];
    }
};
