class Solution {
private:
    int m, n;
    vector<int> memo;
    int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    bool isValid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int traverse(int x, int y, const vector<vector<int>>& matrix) {
        if (memo[n * x + y] != -1) {
            return memo[n * x + y];
        }

        int p = 1;

        for (int i = 0; i < 4; ++i) {
            if (isValid(x + d[i][0], y + d[i][1])) {
                if (matrix[x + d[i][0]][y + d[i][1]] > matrix[x][y]) {
                    p = max(p, traverse(x + d[i][0], y + d[i][1], matrix) + 1);
                }
            }
        }

        memo[n * x + y] = p;
        return p;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        if (m == 0) {
            return 0;
        }
        n = matrix[0].size();
        if (n == 0) {
            return 0;
        }
        memo = vector<int>(m * n, -1);

        int lp = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                lp = max(lp, traverse(i, j, matrix));
            }
        }

        return lp;
    }
};
