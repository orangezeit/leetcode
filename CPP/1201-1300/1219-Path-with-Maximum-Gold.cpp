class Solution {
public:
    int m, n;

    int ans;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    unordered_set<int> visited;

    void dfs(const vector<vector<int>>& grid, int i, int j, int& gold) {
        ans = max(ans, gold);

        for (int k = 0; k < 4; ++k) {
            int nx = i + dirs[k][0];
            int ny = j + dirs[k][1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (!grid[nx][ny]) continue;
            if (visited.count(nx * n + ny)) continue;
            visited.insert(nx * n + ny);
            gold += grid[nx][ny];
            dfs(grid, nx, ny, gold);
            gold -= grid[nx][ny];
            visited.erase(nx * n + ny);

        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        ans = 0;
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    visited.insert(i * n + j);
                    dfs(grid, i, j, grid[i][j]);
                    visited.erase(i * n + j);
                }
            }
        }

        return ans;
    }
};
