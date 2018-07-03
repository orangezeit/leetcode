    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        if (coins.empty()) {
            return -1;
        }
        
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, INT_MAX));
        
        for (int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 0;
            for (int j = 1; j <= amount; ++j) {
                if (i > 0) {
                    dp[i][j] = dp[i-1][j];
                }
                
                if (j >= coins[i]) {
                    if (dp[i][j-coins[i]] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i][j-coins[i]] + 1);
                    }
                }
            }
        }
        
        if (dp[coins.size()-1][amount] == INT_MAX) {
            return -1;
        } else {
            return dp[coins.size()-1][amount];
        }
    }
