class Solution {
private:
    int n, m;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void floodfill(int x, int y, vector<vector<int>>& grid, bool& island) {
        grid[x][y] = 2;
        for (int i = 0; i < 4; ++i) {
            int newx(x + dirs[i][0]), newy(y + dirs[i][1]);
            if (newx < 0 || newx >= n || newy < 0 || newy >= m) {
                island = false;
                continue;
            }
            if (grid[newx][newy] == 0)
                floodfill(newx, newy, grid, island);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans(0);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 0) {
                    bool island(true);
                    floodfill(i, j, grid, island);
                    if (island) ans++;
                }

        return ans;
    }
};
