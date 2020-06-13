class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int c = 0;

        for (int i = 0; i < grid.size() - 1; ++i)
            for (int j = 0; j < grid[0].size() - 1; ++j)
                if (grid[i][j])
                    for (int m = i + 1; m < grid.size(); ++m)
                        for (int n = j + 1; n < grid[0].size(); ++n)
                            if (grid[m][n])
                                if (grid[i][n] == 1 && grid[m][j] == 1)
                                    c++;

        return c;
    }
};
