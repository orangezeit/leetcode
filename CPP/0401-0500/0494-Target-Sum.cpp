class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (S > sum || S < -sum) return 0;
        // [-sum, sum];
        vector<int> dp(2 * sum + 1);
        dp[sum] = 1;
        for (const int& n: nums) {
            vector<int> temp(2 * sum + 1);
            for (int i = 0; i < dp.size(); ++i) {
                if (dp[i]) {
                    temp[i - n] += dp[i];
                    temp[i + n] += dp[i];
                }
            }
            dp = temp;
        }


        return dp[sum + S];
    }
};
