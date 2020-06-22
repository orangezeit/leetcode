class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p(0), m(grid.size()), n(grid[0].size()), dirs[5] = {0, -1, 0, 1, 0};

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    p += 4;
                    for (int k = 0; k < 4; ++k) {
                        int ni(i + dirs[k]), nj(j + dirs[k + 1]);
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n || !grid[ni][nj]) continue;
                        --p;
                    }
                }

        return p;
    }
};
