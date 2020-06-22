class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m(grid.size()), n(grid[0].size()), ans(0), dirs[5] = {0, -1, 0, 1, 0};

        function<void(int, int, int&)> dfs = [&](int x, int y, int& a) {
            ans = max(ans, ++a);
            grid[x][y] = 2;
            for (int i = 0; i < 4; ++i) {
                int nx(x + dirs[i]), ny(y + dirs[i + 1]);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] != 1) continue;
                dfs(nx, ny, a);
            }
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, area);
                }

        return ans;
    }
};
