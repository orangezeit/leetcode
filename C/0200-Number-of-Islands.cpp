    void island(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '2';
        
        if (j != 0) {
            if (grid[i][j-1] == '1') {
                island(grid, i, j-1);
            }
        }
        
        if (j != grid[0].size()-1) {
            if (grid[i][j+1] == '1') {
                island(grid, i, j+1);
            }
        }
        
        if (i != 0) {
            if (grid[i-1][j] == '1') {
                island(grid, i-1, j);
            }
        }
        
        if (i != grid.size()-1) {
            if (grid[i+1][j] == '1') {
                island(grid, i+1, j);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int num = 0;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    island(grid, i, j);
                    num++;
                }
            }
        }
        
        return num;
    }
