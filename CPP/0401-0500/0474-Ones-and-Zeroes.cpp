class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[strs.size() + 1][m + 1][n + 1] = {};

        for (int k = 1; k <= strs.size(); ++k) {

            int z(0), o(0);
            for (const char& c: strs[k-1])
                c == '0' ? z++ : o++;
            for (int i = 0; i <= m; ++i) {
                for (int j = 0; j <= n; ++j) {
                    dp[k][i][j] = max(i >= z && j >= o ? dp[k-1][i - z][j - o] + 1 : 0, dp[k-1][i][j]);
                }
            }
        }

        return dp[strs.size()][m][n];
    }
};
