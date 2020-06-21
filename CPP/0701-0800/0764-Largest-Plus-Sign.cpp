class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int dp[N][N][4] = {};
        unordered_set<int> nones;
        int ans(0);
        for (const vector<int>& mine: mines)
            nones.insert(mine[0] * N + mine[1]);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (!nones.count(i * N + j)) {
                    dp[i][j][0] = (i ? dp[i-1][j][0] : 0) + 1; // up
                    dp[i][j][1] = (j ? dp[i][j-1][1] : 0) + 1; // left
                }
            }
        }

        for (int i = N - 1; i >= 0; --i) {
            for (int j = N - 1; j >= 0; --j) {
                if (!nones.count(i * N + j)) {
                    dp[i][j][2] = (i == N - 1 ? 0 : dp[i+1][j][2]) + 1; // down
                    dp[i][j][3] = (j == N - 1 ? 0 : dp[i][j+1][3]) + 1; // right
                    ans = max(ans, min(dp[i][j][0] ,min(dp[i][j][1], min(dp[i][j][2], dp[i][j][3]))));
                }
            }
        }

        return ans;
    }
};
