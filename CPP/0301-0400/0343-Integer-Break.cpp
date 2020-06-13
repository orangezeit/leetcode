    int integerBreak(int n) {
        // Method 1: Math
        int ans(1), p(1), d(2);
        
        while (p >= ans) {
            p = pow(n / d, d - n % d) * pow(n / d + 1, n % d);
            ans = max(ans, p);
            div++;
        }
        
        return ans;
        
        // Method 2: Dynamic Programming
        vector<int> dp(n+1, 1);
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(i-j, dp[i-j]) * j);
            }
        }
        
        return dp[n];
    }
