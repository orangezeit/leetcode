class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int n(grid.size()), m(grid[0].size()), h(hits.size()), id(0), dirs[5] = {0, -1, 0, 1, 0}, visited[201][201] = {};

        function<bool(int, int)> isValid = [&](int r, int c) {
            return 0 <= r && r < n && 0 <= c && c < m;
        };

        function<bool(int, int)> canFall = [&](int r, int c) {
            if (!isValid(r, c) || !grid[r][c] || visited[r][c] == id) return true;
            if (r == 0) return false;
            visited[r][c] = id;
            for (int d = 0; d < 4; ++d)
                if (!canFall(r + dirs[d], c + dirs[d + 1]))
                    return false;
            return true;
        };

        function<int(int, int)> cnt = [&](int r, int c) {
            if (!isValid(r, c) || !grid[r][c]) return 0;
            grid[r][c] = 0;
            int res(1);
            for (int d = 0; d < 4; ++d)
                res += cnt(r + dirs[d], c + dirs[d + 1]);
            return res;
        };

        vector<int> ans(h);
        for (int i = 0; i < h; ++i) {
            int r(hits[i][0]), c(hits[i][1]), res(0);
            if (!grid[r][c]) continue;
            grid[r][c] = 0;
            for (int d = 0; d < 4; ++d) {
                int x(r + dirs[d]), y(c + dirs[d + 1]);
                if (!isValid(x, y) || !grid[x][y]) continue;
                ++id;
                if (canFall(x, y)) ans[i] += cnt(x, y);
            }
        }
        return ans;
    }
};
