class Solution {
public:
    int containVirus(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size()), dirs[5] = {0, -1, 0, 1, 0};
        int ans(0);
        vector<bool> visited(m * n);
        vector<unordered_set<int>> infected, forward;
        vector<int> walls;

        function<void(int, int)> dfs = [&](int i, int j) {
            infected.back().insert(i * n + j);
            visited[i * n + j] = true;

            for (int k = 0; k < 4; ++k) {
                int ni = i + dirs[k];
                int nj = j + dirs[k + 1];

                if (ni < 0 || ni >= m || nj < 0 || nj >= n || visited[ni * n + nj]) continue;

                if (grid[ni][nj] == 1) {
                    dfs(ni, nj);
                } else if (grid[ni][nj] == 0) {
                    forward.back().insert(ni * n + nj);
                    walls.back()++;
                }
            }
        };

        while (true) {
            fill(visited.begin(), visited.end(), false);

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && !visited[i * n + j]) {
                        infected.push_back({});
                        forward.push_back({});
                        walls.emplace_back(0);
                        dfs(i, j);
                    }
                }
            }

            if (infected.empty()) break;

            int idx(0), cells(0);

            for (int i = 0; i < forward.size(); ++i) {
                if (forward[i].size() > cells) {
                    cells = forward[i].size();
                    idx = i;
                }
            }

            ans += walls[idx];
            forward.erase(forward.begin() + idx);


            for (const int& c: infected[idx])
                grid[c / n][c % n] = 2;
            for (const auto& f: forward)
                for (const int& c: f)
                    grid[c / n][c % n] = 1;

            if (forward.empty()) break;
            infected.clear();
            forward.clear();
            walls.clear();
        }

        return ans;
    }
};
