class Solution {
private:
    int m, n;
    vector<vector<bool>> visited;

    bool valid(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int d[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};

    bool flow(vector<vector<int>>& matrix, int x, int y, int xt, int yt) {
        //cout << x << y << endl;
        if (x == xt || y == yt) {
            return true;
        }

        bool canFlow = false;

        for (int i = 0; i < 4; ++i) {
            if (valid(x+d[i][0], y+d[i][1])) {
                if (matrix[x+d[i][0]][y+d[i][1]] <= matrix[x][y] && !visited[x+d[i][0]][y+d[i][1]]) {
                    visited[x+d[i][0]][y+d[i][1]] = true;
                    canFlow |= flow(matrix, x+d[i][0], y+d[i][1], xt, yt);
                    visited[x+d[i][0]][y+d[i][1]] = false;

                    if (canFlow) {
                        return true;
                    }
                }
            }
        }

        //visited[x][y] = true;
        return canFlow;
    }

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {

        vector<pair<int, int>> res;

        if (matrix.empty()) {
            return res;
        }
        m = matrix.size();
        n = matrix[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bool a = flow(matrix, i, j, 0, 0);
                bool b = flow(matrix, i, j, m-1, n-1);

                if (a && b) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
