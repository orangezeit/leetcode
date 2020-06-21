class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size()), dirs[5] = {0, -1, 0, 1, 0};
        int k = max(grid.front().front(), grid.back().back());
        bool visited[m * n];

        function<void(int, int, int)> dfs = [&](int i, int j, int level) {
            visited[i * n + j] = true;
            for (int d = 0; d < 4; ++d) {
                int ni(i + dirs[d]), nj(j + dirs[d + 1]);
                if (ni < 0 || ni >= m || nj < 0 || nj >= n ||
                    visited[ni * n + nj] || grid[ni][nj] > level) continue;
                dfs(ni, nj, level);
            }
        };

        while (true) {
            fill(visited, visited + m * n, false);
            dfs(0, 0, k++);
            if (visited[m * n - 1]) break;
        }

        return k - 1;
    }
};
