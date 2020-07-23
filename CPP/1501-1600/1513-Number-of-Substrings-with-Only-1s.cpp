class Solution {
public:
    int numSub(string s) {
        const int n(s.length()), mod(1e9+7);
        int ans(0);
        vector<int> dp(n);
        for (int i = 0; i < n; ++i)
            if (s[i] == '1')
                ans = (ans + (dp[i] = (i ? dp[i-1] : 0) + 1)) % mod;
        return ans;
    }
};
