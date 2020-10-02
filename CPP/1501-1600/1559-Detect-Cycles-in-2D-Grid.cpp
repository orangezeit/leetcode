class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        const int m(grid.size()), n(grid[0].size()), dirs[5] = {0, -1, 0, 1, 0};
        vector<vector<bool>> visited(m, vector<bool>(n));

        function<bool(int, int, int, int)> detect = [&](int x, int y, int px, int py) {
            visited[x][y] = true;

            for (int k = 0; k < 4; ++k) {
                int nx(x + dirs[k]), ny(y + dirs[k + 1]);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != grid[x][y]) continue;
                if (px == nx && py == ny) continue;
                if (visited[nx][ny] || detect(nx, ny, x, y)) return true;
            }

            return false;
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!visited[i][j] && detect(i, j, -1, -1))
                    return true;

        return false;
    }
};
