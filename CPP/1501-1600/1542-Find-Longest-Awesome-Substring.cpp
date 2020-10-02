class Solution {
public:
    int longestAwesome(string s) {
        int n = s.length(), ans(1), mask(0);
        vector<int> dp(1024, n);
        dp[0] = -1;

        for (int i = 0; i < n; ++i) {
            mask ^= 1 << (s[i] - '0');
            for (int k = 0; k < 1024; ++k)
                if (__builtin_popcount(mask ^ k) <= 1)
                    ans = max(ans, i - dp[k]);
            dp[mask] = min(i, dp[mask]);
        }
        return ans;
    }
};
