class Solution {
public:
    int dirs[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N));
        dp[r][c] = 1;
        double ans(1.0);
        while(K--) {
            ans /= 8;
            vector<vector<double>> temp(N, vector<double>(N));
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < N; ++j)
                    if (dp[i][j])
                        for (int k = 0; k < 8; ++k) {
                            int newi = i + dirs[k][0];
                            int newj = j + dirs[k][1];
                            if (newi >= 0 && newi < N && newj >= 0 && newj < N)
                                temp[newi][newj] += dp[i][j];
                        }
            dp = temp;
        }
        double sum(0.0);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                sum += dp[i][j];
        return sum * ans;
    }
};
