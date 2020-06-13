class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> verticals(grid.size()), horizons(grid[0].size());

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    verticals[i]++;
                    horizons[j]++;
                }
            }
        }

        int m(INT_MAX), n(INT_MAX);

        for (int i = 0; i < grid.size(); ++i) {
            int temp(0);
            for (int j = 0; j < grid.size(); ++j) {
                temp += verticals[j] * abs(i - j);
            }
            m = min(m, temp);
        }

        for (int i = 0; i < grid[0].size(); ++i) {
            int temp(0);
            for (int j = 0; j < grid[0].size(); ++j) {
                temp += horizons[j] * abs(i - j);
            }
            n = min(n, temp);
        }
        return m + n;
    }
};
