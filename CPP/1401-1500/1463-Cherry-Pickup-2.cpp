class Solution {
public:
    unordered_map<int, int> rec;
    int n, m;
    int dfs(const vector<vector<int>>& grid, int y1, int y2, int x) {
        if (x == n) return 0;
        if (y1 < 0 || y1 >= m || y2 < 0 || y2 >= m) return 0;
        if (rec.count((y1 << 16) + (y2 << 8) + x)) return rec[(y1 << 16) + (y2 << 8) + x];
        int s(0);
        for (int i: {-1, 0, 1})
            for (int j: {-1, 0, 1})
                s = max(s, dfs(grid, y1 + i, y2 + j, x + 1));
        return rec[(y1 << 16) + (y2 << 8) + x] = (y1 == y2 ? grid[x][y1] : (grid[x][y1] + grid[x][y2])) + s;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        return dfs(grid, 0, m - 1, 0);
    }
};
