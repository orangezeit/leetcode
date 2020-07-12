class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        const int n(prices.size());
        if (k >= n / 2) {
            int profit(0);
            for (int i = 1; i < n; ++i)
                profit += max(0, prices[i] - prices[i - 1]);
            return profit;
        }

        vector<int> dp(n);
        for (int i = 1; i <= k; ++i) {
            int maxDiff = -prices[0];
            for (int j = 1; j < n; ++j) {
                int prev = dp[j];
                dp[j] = max(dp[j-1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, prev - prices[j]);
            }
        }

        return dp.back();
    }
};
