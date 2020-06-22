class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n(nums.size());
        long dp[2][n];
        //long sums[n+1] = {};
        vector<long> sums(n + 1);
        for (int i = 1; i <= n; ++i)
            dp[1][i-1] = sums[i] = sums[i-1] + nums[i-1];

        for (int k = 2; k <= m; ++k) {
            for (int i = k-1; i < n; ++i) {
                    dp[k % 2][i] = INT_MAX;
                    for (int j = k - 1; j <= i; ++j)
                        dp[k % 2][i] = min(dp[k % 2][i], max(dp[(k-1) % 2][j-1], sums[i+1] - sums[j]));
            }
        }
        return dp[m % 2][n - 1];
    }
};
