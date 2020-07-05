class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        if (d * f < target) return 0;
        vector<int> dp(d * f + 1);
        dp[0] = 1;

        for (int i = 1; i <= d; ++i) {
            vector<int> temp(d * f + 1, 0);
            for (int j = i; j <= f * i; ++j)
                for (int k = 1; k <= min(j, f); ++k)
                    temp[j] = (temp[j] + dp[j-k]) % 1000000007;
            dp = temp;
        }

        return dp[target];
    }
};
