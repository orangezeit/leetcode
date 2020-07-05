class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        // bfs
        int m(mat.size()), n(mat[0].size());
        unordered_set<int> visited; // bits
        queue<int> q;
        int k(0);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    k += (1 << (i * n + j));
                }
            }
        }

        if (k == 0) return 0;
        q.push(k);
        visited.insert(k);

        int steps(1);
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int t = q.front();
                q.pop();
                vector<vector<int>> temp(m, vector<int>(n));

                for (int i = 0; i < m * n; ++i) {
                    if (t & (1 << i)) {
                        //cout << i << "a" << endl;
                        temp[i / n][i % n]++;
                    }
                }

                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        vector<pair<int, int>> changed;
                        temp[i][j] = temp[i][j] ? 0 : 1;
                        changed.push_back({i, j});

                        for (int x = 0; x < 4; ++x) {
                            int ni(i + dirs[x][0]), nj(j + dirs[x][1]);
                            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                            temp[ni][nj] = temp[ni][nj] ? 0 : 1;
                            changed.push_back({ni, nj});
                        }
                        int d(0);

                        for (int a = 0; a < m; ++a) {
                            for (int b = 0; b < n; ++b) {
                                if (temp[a][b]) {
                                    d += (1 << (a * n + b));
                                }
                            }
                        }

                        if (d == 0) return steps;

                        for (pair<int, int> p: changed) {
                            temp[p.first][p.second] = temp[p.first][p.second] ? 0 : 1;
                        }

                        if (visited.count(d)) continue;
                        q.push(d);
                        visited.insert(d);
                    }
                }
            }
            ++steps;

        }

        return -1;
    }
};
