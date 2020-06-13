class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        // dp
        int dp[M.size()][M[0].size()][4] = {};
        int ans(0);

        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M[0].size(); ++j) {
                if (M[i][j]) {
                    for (int k = 0; k < 4; ++k)
                        dp[i][j][k] = 1;
                    // case 1: diagonal
                    if (i && j) dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-1][0] + 1);
                    ans = max(ans, dp[i][j][0]);

                    // case 2: anti-diagonal
                    if (i && j < M[0].size() - 1) dp[i][j][1] = max(dp[i][j][1], dp[i-1][j+1][1] + 1);
                    ans = max(ans, dp[i][j][1]);

                    // case 3: vertical
                    if (i) dp[i][j][2] = max(dp[i][j][2], dp[i-1][j][2] + 1);
                    ans = max(ans, dp[i][j][2]);

                    // case 4: horizontal
                    if (j) dp[i][j][3] = max(dp[i][j][3], dp[i][j-1][3] + 1);
                    ans = max(ans, dp[i][j][3]);

                }
            }
        }

        return ans;
    }
};
