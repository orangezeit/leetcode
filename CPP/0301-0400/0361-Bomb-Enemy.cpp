class Solution {
public:
    int simulation(vector<vector<char>>& grid, int r, int c) {
        int k = 0;

        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][c] == 'W')
                break;

            if (grid[i][c] == 'E')
                k++;
        }

        for (int i = r + 1; i < grid.size(); i++) {
            if (grid[i][c] == 'W')
                break;

            if (grid[i][c] == 'E')
                k++;
        }

        for (int i = c - 1; i >= 0; i--) {
            if (grid[r][i] == 'W')
                break;

            if (grid[r][i] == 'E')
                k++;
        }

        for (int i = c + 1; i < grid[0].size(); i++) {
            if (grid[r][i] == 'W')
                break;

            if (grid[r][i] == 'E')
                k++;
        }

        return k;
    }

    int maxKilledEnemies(vector<vector<char>>& grid) {
        int maxKilled = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '0')
                    maxKilled = max(maxKilled, simulation(grid, i, j));
            }
        }

        return maxKilled;
    }
};
