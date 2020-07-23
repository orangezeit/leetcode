class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            if (dp[i]) continue;
            for (int j = 1; i + j * j <= n; ++j)
                dp[i + j * j] = true;
        }
        return dp[n];
    }
};
