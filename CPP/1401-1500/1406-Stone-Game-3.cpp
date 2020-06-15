class Solution {
public:
    string stoneGameIII(vector<int>& sv) {
        int n(sv.size());
        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; --i) {

            if (i == n - 1) {
                dp[n - 1] = sv[n - 1];
            } else if (i == n - 2) {
                dp[n - 2] = max(sv[n - 2] + sv[n - 1], sv[n - 2] - sv[n - 1]);
            } else {
                int c1 = sv[i] + sv[i+1] + sv[i+2] - dp[i + 3];
                int c2 = sv[i] + sv[i+1] - dp[i + 2];
                int c3 = sv[i] - dp[i+1];
                dp[i] = max(c1, max(c2, c3));
            }
        }

        return dp[0] > 0 ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
    }
};
