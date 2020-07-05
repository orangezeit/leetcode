class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n(grid.size()), m(grid[0].size());

        vector<vector<int>> new_grid(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                new_grid[(i * m + j + k) % (m * n) / m][(i * m + j + k) % (m * n) % m] = grid[i][j];
        return new_grid;
    }
};
