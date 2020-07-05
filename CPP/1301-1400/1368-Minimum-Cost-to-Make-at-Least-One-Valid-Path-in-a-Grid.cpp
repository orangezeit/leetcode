class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size()), dirs[4][2]({{0, 1}, {0, -1}, {1, 0}, { -1, 0}});
        int cost(0);
        queue<int> q;
        bool seen[m * n] = {};

        function<void(const int&, const int&)> dfs = [&](const int& r, const int& c) {
            if (r < 0 || r >= m || c < 0 || c >= n || seen[r * n + c]) return;
            q.push(r * n + c);
            seen[r * n + c] = true;
            dfs(r + dirs[grid[r][c] - 1][0], c + dirs[grid[r][c] - 1][1]);
        };

        dfs(0, 0);

        while (!q.empty()) {
            if (seen[m * n - 1]) return cost;
            ++cost;
            int s = q.size();
            while (s--) {
                int p = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i)
                    dfs(p / n + dirs[i][0], p % n + dirs[i][1]);
            }
        }

        return -1;
    }
};
