class Solution {
public:
    int dirs[8][2] = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}};

    int knightDialer(int N) {
        vector<vector<int>> dp(4, vector<int>(3, 1));
        dp[3][0] = 0;
        dp[3][2] = 0;

        while (--N) {
            vector<vector<int>> temp(4, vector<int>(3));
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 3; ++j)
                    if (dp[i][j])
                        for (int k = 0; k < 8; ++k) {
                            int newi = i + dirs[k][0];
                            int newj = j + dirs[k][1];
                            if (newi >= 0 && newi < 4 && newj >= 0 && newj < 3)
                                temp[newi][newj] = (temp[newi][newj] + dp[i][j]) % 1000000007;
                        }
            swap(dp, temp);
            dp[3][0] = 0;
            dp[3][2] = 0;
        }

        int sum(0);
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 3; ++j)
                sum = (sum + dp[i][j]) % 1000000007;
        return sum;
    }
};
