class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        const int m(grid.size()), n(grid[0].size()), dirs[5] = {0, -1, 0, 1, 0};
        int ans(0);
        vector<bool> visited(m * n);

        function<void(int, int)> dfs = [&](int x, int y) {
            visited[x * n + y] = true;
            for (int k = 0; k < 4; ++k) {
                int nx(x + dirs[k]), ny(y + dirs[k + 1]);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '0' || visited[nx * n + ny])
                    continue;
                dfs(nx, ny);
            }
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1' && !visited[i * n + j]) {
                    ans++;
                    dfs(i, j);
                }
        return ans;
    }
};
