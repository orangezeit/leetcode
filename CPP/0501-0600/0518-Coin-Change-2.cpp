class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1] = {1};

        for (const int& coin: coins)
            for (int i = 1; i <= amount; ++i)
                if (i >= coin) dp[i] += dp[i - coin];
        return dp[amount];
    }
};
