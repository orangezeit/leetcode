class Solution {
public:

    int minimumMoves(vector<int>& arr) {
        int n(arr.size());

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        // edge case 1: every single letter takes one step to remove
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        // edge case 2: two consecutive letter takes one step to remove if same else two steps

        for (int i = 0; i < n - 1; ++i)
            dp[i][i+1] = arr[i] == arr[i+1] ? 1 : 2;

        for (int len = 3; len <= n; len++) {
            for (int i = 0, j = i + len - 1; j < n; i++, j++) {
                if (arr[i] == arr[j])
                    dp[i][j] = dp[i+1][j-1];
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }

        return dp[0][n-1];
    }
};
