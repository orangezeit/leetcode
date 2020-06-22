class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n(ring.length());
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (const char& c: key) {
            vector<int> new_dp(n, INT_MAX);
            for (int i = 0; i < n; ++i) {
                if (ring[i] != c) continue;
                for (int j = 0; j < n; ++j) {
                    if (dp[j] != INT_MAX) {
                        int k = abs(j - i);
                        new_dp[i] = min(new_dp[i], dp[j] + min(k, n - k) + 1);
                    }
                }
            }
            swap(dp, new_dp);
        }
        int ans(INT_MAX);
        for (int i = 0; i < n; ++i)
            if (ring[i] == key.back())
                ans = min(ans, dp[i]);
        return ans;
    }
};
