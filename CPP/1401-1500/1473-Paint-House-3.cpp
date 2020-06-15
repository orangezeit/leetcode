class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[k][i][c]: min cost to form k neighbors with first i houses, end with color c
        int s(1);
        vector<vector<vector<int>>> dp(target + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 1e9)));
        fill(dp[0][0].begin(), dp[0][0].end(), 0);
        for (int k = 1; k <= target; ++k) {
            for (int i = k; i <= m; ++i) {
                int hi = houses[i-1];
                int hj = i > 1 ? houses[i-2] : 0;
                const auto& [si, ei] = hi ? tie(hi, hi) : tie(s, n);
                const auto& [sj, ej] = hj ? tie(hj, hj) : tie(s, n);
                for (int ci = si; ci <= ei; ++ci) {
                    int c = ci == hi ? 0 : cost[i - 1][ci - 1];
                    for (int cj = sj; cj <= ej; ++cj) {
                        dp[k][i][ci] = min(dp[k][i][ci], dp[k - (ci != cj)][i - 1][cj] + c);
                    }
                }
            }
        }
        int ans = *min_element(dp[target][m].begin(), dp[target][m].end());
        return ans > 1e7 ? -1 : ans;
    }
};
