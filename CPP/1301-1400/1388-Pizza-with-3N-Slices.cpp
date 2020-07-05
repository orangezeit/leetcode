class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        // Time Complexity: O(N^2)
        // Space Complexity: O(N)
        int n = slices.size();
        auto maxSum = [&](bool left) {
            vector<vector<int>> dp(3, vector<int>(n / 3 + 1));
            int ans(0);
            for (int i = 2; i <= n; ++i) {
                for (int j = 1; j <= n / 3; ++j)
                    dp[i % 3][j] = max(dp[(i - 1) % 3][j], dp[(i - 2) % 3][j - 1] + slices[i - (left ? 2 : 1)]);
                ans = max(ans, dp[i % 3][n / 3]);
            }
            return ans;
        };
        return max(maxSum(true), maxSum(false));
    }
};
