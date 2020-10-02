class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int n(grid.size()), m(grid[0].size()), c(0), dirs[5] = {0, -1, 0, 1, 0};
        bool visited[n * m];
        vector<int> lands;
        bool traverse(true);

        function<void(int, int)> dfs = [&](int x, int y) {
            visited[x * m + y] = true;
            if (traverse) lands.emplace_back(x * m + y);
            else c++;
            for (int d = 0; d < 4; ++d) {
                int nx(x + dirs[d]), ny(y + dirs[d + 1]);
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || !grid[nx][ny] || visited[nx * m + ny]) continue;
                dfs(nx, ny);
            }
        };

        memset(visited, false, n * m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] && !visited[i * m + j]) {
                    dfs(i, j);
                    if (++c > 1) return 0;
                }

        traverse = false;
        int t = lands.size();
        for (int i = 0; i < t; ++i) {
            int cur(lands[i]), nxt(lands[(i + 1) % t]);
            grid[cur / m][cur % m] = 0;
            c = 0;
            memset(visited, false, n * m);
            dfs(nxt / m, nxt % m);
            if (c + 1 != t) return 1;
            grid[cur / m][cur % m] = 1;
        }

        return 2;
    }
};
