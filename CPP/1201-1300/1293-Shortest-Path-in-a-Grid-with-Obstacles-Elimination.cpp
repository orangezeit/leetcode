class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        // bfs
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int m(grid.size()), n(grid[0].size());
        int t(m * n - 1);
        set<pair<int, int>> visited({{0, k}});

        queue<pair<int, int>> q; // loc, obs
        q.push({0, k});
        int steps(0);

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                pair<int, int> p = q.front();
                q.pop();

                int x = p.first / n;
                int y = p.first % n;
                //cout << x << " " << y << endl;
                for (int i = 0; i < 4; ++i) {
                    int nx(x + dirs[i][0]), ny(y + dirs[i][1]);
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (visited.count({nx * n + ny, p.second - (grid[nx][ny])})) continue;
                    if (nx == m - 1 && ny == n - 1) return steps + 1;

                    int c = p.second;
                    if (grid[nx][ny]) c--;
                    if (c < 0) continue;
                    q.push({nx * n + ny, c});
                    visited.insert({nx * n + ny, c});
                }
            }
            ++steps;
        }

        return t == 0 ? 0 : -1;
    }
};
