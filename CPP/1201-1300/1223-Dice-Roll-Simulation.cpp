class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<long>> dp(n + 1, vector<long>(6));
        for (int i = 0; i < 6; ++i) dp[1][i] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < 6; ++j) {
                for (int k = 0; k < 6; ++k) {
                    if (j != k) {
                        dp[i][j] += dp[i-1][k] % 1000000007;
                        dp[i][j] %= 1000000007;
                    } else {
                        if (i <= rollMax[j]) {
                            dp[i][j] += dp[i-1][k] % 1000000007;
                            dp[i][j] %= 1000000007;
                        }
                        else {
                            for (int m = 0; m < 6; ++m) {
                                if (m != j && rollMax[j] - 1 > 0) {
                                    for (int p = rollMax[j]; p > 1; --p) {
                                        dp[i][j] += dp[i-p][m] % 1000000007;
                                        dp[i][j] %= 1000000007;
                                    }

                                }


                            }
                        }
                    }
                }
            }
        }

        long ans(0);
        for (int i = 0; i < 6; ++i) ans += dp.back()[i];

        return (ans % 1000000007);
    }
};
