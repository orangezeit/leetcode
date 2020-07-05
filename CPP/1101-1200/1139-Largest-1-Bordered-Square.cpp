class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size()), r(min(m, n));
        vector<vector<int>> right_add(grid), down_add(grid);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (i) down_add[i][j] += down_add[i-1][j];
                if (j) right_add[i][j] += right_add[i][j-1];
            }

        for (int k = r-1; k >= 0; --k) {
            for (int i = 0; i < m - k; ++i) {
                for (int j = 0; j < n - k; ++j) {
                    int a = i == 0 ? down_add[i+k][j] : down_add[i+k][j] - down_add[i-1][j];
                    if (a != k + 1) continue;

                    int b = i == 0 ? down_add[i+k][j+k] : down_add[i+k][j+k] - down_add[i-1][j+k];
                    if (b != k + 1) continue;

                    int c = j == 0 ? right_add[i+k][j+k] : right_add[i+k][j+k] - right_add[i+k][j-1];
                    if (c != k + 1) continue;

                    int d = j == 0 ? right_add[i][j+k] : right_add[i][j+k] - right_add[i][j-1];
                    if (d != k + 1) continue;

                    return (k+1) * (k+1);
                }
            }
        }

        return 0;
    }
};
