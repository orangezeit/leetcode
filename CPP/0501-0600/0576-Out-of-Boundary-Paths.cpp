class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<long>> dp(m, vector<long>(n));
        dp[i][j] = 1;
        int total(0), remain(0);


        while(N--) {
            vector<vector<long>> temp(m, vector<long>(n));
            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    if (dp[i][j])
                        for (int k = 0; k < 4; ++k) {
                            int newi = i + dirs[k][0];
                            int newj = j + dirs[k][1];
                            if (newi >= 0 && newi < m && newj >= 0 && newj < n)
                                temp[newi][newj] = (temp[newi][newj] + dp[i][j]) % 1000000007;
                        }

            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j) {
                    total = (total + dp[i][j] * 4) % 1000000007;
                    remain = (remain + temp[i][j]) % 1000000007;
                }

            dp = temp;
        }

        return (total - remain + 1000000007) % 1000000007;
    }
};
