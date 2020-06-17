class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int r(grid.size()), c(grid[0].size()), dirs[5] = {0, 1, 0, -1, 0};
        vector<bool> visited(r * c);
        unordered_set<int> border;
        function<void(int, int, const int&)> dfs = [&](int x, int y, const int& clr) {
            visited[x * c + y] = true;
            int d(0);
            for (int i = 0; i < 4; ++i) {
                int nx(x + dirs[i]), ny(y + dirs[i + 1]);
                if (nx < 0 || nx >= r || ny < 0 || ny >= c || grid[nx][ny] != clr) continue;
                d++;
                if (visited[nx * c + ny]) continue;
                dfs(nx, ny, clr);
            }
            if (d < 4) border.insert(x * c + y);
        };

        dfs(r0, c0, grid[r0][c0]);
        for (const int& b: border)
            grid[b / c][b % c] = color;
        return grid;
    }
};
