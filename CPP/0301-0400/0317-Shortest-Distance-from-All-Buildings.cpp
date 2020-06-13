class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //vector<vector<int>> marked(m, vector<int>(n));

        int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue<int> q;
        unordered_set<int> persons, traps;
        unordered_map<int, int> marks;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == 1) {
                    persons.insert(i * n + j);
                } else if (grid[i][j] == 2) {
                    traps.insert(i * n + j);
                }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (persons.count(i * n + j)) {
                    q.push(i * n + j);
                    int steps = 1;
                    unordered_set<int> visited;
                    visited.insert(i * n + j);

                    while (!q.empty()) {
                        int s = q.size();
                        while (s--) {
                            int temp = q.front();
                            q.pop();

                            for (int k = 0; k < 4; ++k) {
                                int newi = temp / n + dirs[k][0];
                                int newj = temp % n + dirs[k][1];

                                if (newi < 0 || newi >= m || newj < 0 || newj >=n) continue;
                                if (visited.count(newi * n + newj)) continue;
                                if (persons.count(newi * n + newj)) continue;
                                if (traps.count(newi * n + newj)) continue;

                                visited.insert(newi * n + newj);
                                marks[newi * n + newj]++;

                                grid[newi][newj] += steps;
                                q.push(newi * n + newj);
                            }
                        }
                        steps++;
                    }
                }
        int ans(INT_MAX);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (marks[i * n + j] == persons.size())
                    ans = min(ans, grid[i][j]);

        return ans == INT_MAX ? -1 : ans;
    }
};
