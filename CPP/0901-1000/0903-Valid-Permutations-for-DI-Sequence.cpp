class Solution {
public:
    int numPermsDISequence(string S) {
        int n(S.length()), mod(1e9+7);
        S = '#' + S;
        vector<vector<long>> dp(n+1, vector<long>(n+1));
        dp[0][0] = 1;
        long ans(0);

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (S[i] == 'I') {
                    for (int k = 0; k <= j - 1; ++k) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= mod;
                    }
                } else {
                    for (int k = j; k <= i - 1; ++k) {
                        dp[i][j] += dp[i-1][k];
                        dp[i][j] %= mod;
                    }
                }
                if (i == n) ans = (ans + dp[i][j]) % mod;
            }
        }

        return ans;
    }
};
