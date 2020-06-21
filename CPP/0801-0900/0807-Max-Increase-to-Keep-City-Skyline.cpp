class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int increase = 0;
        vector<int> horizontal(grid.size(), 0);
        vector<int> vertical(grid.size(), 0);

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (horizontal[j] < grid[i][j]) {
                    horizontal[j] = grid[i][j];
                }
                if (vertical[i] < grid[i][j]) {
                    vertical[i] = grid[i][j];
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                if (grid[i][j] < min(vertical[i], horizontal[j])) {
                    increase = increase + min(vertical[i], horizontal[j])-grid[i][j];
                    grid[i][j] = min(vertical[i], horizontal[j]);
                }
            }
        }
        return increase;
    }
};
