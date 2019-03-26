private:
    int m, n;
    int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool verify(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    int surfaceArea(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int area = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) area += 2;
                for (int k = 0; k < 4; ++k) {
                    verify(i + d[k][0], j + d[k][1]) ? area += max(grid[i + d[k][0]][j + d[k][1]] - grid[i][j], 0) : area += grid[i][j];
                }
            }
        }
        
        return area;
    }
