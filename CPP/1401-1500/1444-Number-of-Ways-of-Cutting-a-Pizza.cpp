class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        // Time Complexity: O(r * c * k * (r + c))
        // Space Complexity: O(n * k)
        const int r(pizza.size()), c(pizza[0].size()), mod(1e9 + 7);
        unordered_map<int, int> memo;

        vector<vector<int>> dp(r, vector<int>(c));
        // dp[i][j] records the number of apples of pizza[0:i][0:j]
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)  {
                if (pizza[i][j] == 'A') dp[i][j]++;
                if (i) dp[i][j] += dp[i - 1][j];
                if (j) dp[i][j] += dp[i][j - 1];
                if (i && j) dp[i][j] -= dp[i - 1][j - 1];
            }

        function<bool(int, int, int, int)> check = [&](int x1, int x2, int y1, int y2) {
            return dp[x2][y2] - (x1 ? dp[x1 - 1][y2] : 0)
                              - (y1 ? dp[x2][y1 - 1] : 0) + (x1 && y1 ? dp[x1 - 1][y1 - 1] : 0) > 0;
        };

        function<int(int, int, int)> dfs = [&](int x, int y, int p) {
            if (memo.count(x * 10000 + y * 100 + p))
                return memo[x * 10000 + y * 100 + p];
            if (p == 1) // base case
                return memo[x * 10000 + y * 100 + p] = check(x, r - 1, y, c - 1) ? 1 : 0;

            int ans(0);

            for (int i = x + 1; i < r; ++i)
                if (check(x, i - 1, y, c - 1)) {
                    ans += dfs(i, y, p - 1);
                    ans %= mod;
                }

            for (int j = y + 1; j < c; ++j)
                if (check(x, r - 1, y, j - 1)) {
                    ans += dfs(x, j, p - 1);
                    ans %= mod;
                }

            return memo[x * 10000 + y * 100 + p] = ans;
        };

        return dfs(0, 0, k);
    }
};
