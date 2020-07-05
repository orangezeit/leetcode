class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < ranges.size(); ++i) {
            int tmp = INT_MAX;
            for (int c = max(0, i-ranges[i]); c <= min(i + ranges[i], n); ++c)
                if (dp[c] != INT_MAX)
                    tmp = min(tmp, dp[c] + 1);
            for (int k = max(0, i-ranges[i]); k <= min(i + ranges[i], n); ++k) {
                dp[k] = min(dp[k], tmp);
            }
        }
        if (dp.back() == INT_MAX) dp.back() = -1;
        return dp.back();
    }
};
