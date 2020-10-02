class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        const int n(s.length()), t(n - k);
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 100));
        dp[n][t] = 0;
        auto cal = [](int c) {return c <= 1 ? c : c <= 9 ? 2 : c <= 99 ? 3 : 4;};
        for (int p = n - 1; p >= 0; --p) {
            for (int cnt = 0; cnt <= t; ++cnt) {
                for (int j = p, same = 0; j < n; ++j) {
                    if (s[p] == s[j]) same++;
                    if (cnt + same > t) break;
                    dp[p][cnt] = min(dp[p][cnt], cal(same) + dp[j + 1][cnt + same]);
                }
                dp[p][cnt] = min(dp[p][cnt], dp[p + 1][cnt]);
            }
        }
        return dp[0][0];
    }
};
