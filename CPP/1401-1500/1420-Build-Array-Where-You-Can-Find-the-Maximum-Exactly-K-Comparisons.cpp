class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<long>> dp(m + 1, vector<long>(n + 2));
        const int mod(1e9+7);

        for (int i = 1; i <= m; ++i)
            dp[i][1] = 1;

        for (int i = 1; i < n; ++i) {
            vector<vector<long>> np(m + 1, vector<long>(n + 2));
            for (int x = 1; x <= m; ++x) { // old max among arr[:i]
                for (int y = 1; y <= m; ++y) { // val at arr[i]
                    for (int c = 1; c <= k; ++c) { // cost, up to k
                        np[max(x, y)][c + (y > x)] += dp[x][c];
                        np[max(x, y)][c + (y > x)] %= mod;
                    }
                }
            }
            swap(np, dp);
        }

        long ans(0);
        for (int i = 1; i <= m; ++i) {
            ans += dp[i][k];
            ans %= mod;
        }
        return ans;
    }
};
