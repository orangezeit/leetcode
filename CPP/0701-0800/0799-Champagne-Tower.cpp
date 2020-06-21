class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[100][100] = {};
        dp[0][0] = poured;

        for (int i = 1; i <= 99; ++i) {
            bool noNext = true;
            for (int j = 0; j < 99; ++j) {
                if (dp[i-1][j] > 1) {
                    noNext = false;
                    dp[i][j] += (dp[i-1][j] - 1) / 2;
                    dp[i][j + 1] += (dp[i-1][j] - 1) / 2;
                    dp[i-1][j] = 1;
                }
            }
            if (noNext) break;
        }

        return dp[query_row][query_glass];
    }
};
