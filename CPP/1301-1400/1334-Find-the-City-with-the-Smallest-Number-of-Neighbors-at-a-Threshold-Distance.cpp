class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (const vector<int>& e: edges)
            dp[e[0]][e[1]] = dp[e[1]][e[0]] = e[2];
        for (int i = 0; i < n; ++i) dp[i][i] = 0;
        int mn(n), ans(0);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        for (int i = 0; i < n; ++i) {
            int cnt(0);
            for (int j = 0; j < n; ++j)
                if (dp[i][j] <= dt) cnt++;
            if (cnt > mn) continue;
            mn = cnt;
            ans = i;
        }

        return ans;
    }
};
