class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end());
        int n(envelopes.size());
        vector<int> dp(n, 1);
        int ans(1);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (envelopes[i][0] < envelopes[j][0] && envelopes[i][1] < envelopes[j][1]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                    ans = max(ans, dp[j]);
                }
            }
        }

        return ans;
    }
};
