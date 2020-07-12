class Solution {
public:
    int numDistinct(string s, string t) {
        // Time Complexity: O(N1 N2)
        // Space Complexity: O(N1)
        const int n1(s.length()), n2(t.length());
        int dp[2][n1 + 1] = {};

        for (int j = 0; j <= n1; ++j) dp[0][j] = 1;
        for (int i = 1; i <= n2; ++i)
            for (int j = 1; j <= n1; ++j)
                dp[i % 2][j] = (s[i - 1] == t[i - 1] ? dp[(i - 1) % 2][j - 1] : 0) + dp[i % 2][j - 1];

        return dp[n2 % 2][n1];
    }
};
