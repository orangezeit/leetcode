class Solution {
public:
    int numWays(int steps, int arrLen) {
        int len(min(steps / 2 + 1, arrLen)), mod(1e9 + 7);
        vector<long> dp(len);
        dp[0] = 1;

        while (steps--) {
            vector<long> new_dp(len);
            for (int i = 0; i < len; ++i) {
                new_dp[i] = (dp[i] + (i ? dp[i-1] : 0) + (i < len - 1 ? dp[i+1] : 0)) % mod;
                if (!new_dp[i]) break;
            }
            swap(dp, new_dp);
        }

        return dp[0];
    }
};
