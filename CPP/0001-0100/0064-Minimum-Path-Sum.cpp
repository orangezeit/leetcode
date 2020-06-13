    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i && j) {
                    grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j];
                } else if (i) {
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                } else if (j) {
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                }
            }
        }
        
        return grid.back().back();
    }
