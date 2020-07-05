class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        unordered_map<int, unordered_set<int>> visited; // two cell indices
        int len(grid.size()), w(grid[0].size());
        queue<pair<int, int>> q;
        q.push({0, 1});
        int steps = 1;
        visited[0].insert(1);

        // target len * wid - 1, len * wid - 2
        // move 1: +1 +1
        // down: + wid, + wid
        // rotate clock: +0, -1 + wid
        // rotate counter: +0, - wid + 1

        int dirs[4][2] = {{1, 1}, {w, w}, {0, w - 1}, {0, 1 - w}};

        while (!q.empty()) {
            int s = q.size();

            while (s--) {
                pair<int, int> p = q.front();

                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int xy1 = p.first + dirs[i][0];
                    int xy2 = p.second + dirs[i][1];

                    if (xy2 - xy1 != 1 && xy2 - xy1 != w) continue;
                    if (xy1 < 0 || xy1 >= len * w || xy2 < 0 || xy2 >= len * w) continue;
                    if (visited.count(xy1) && visited[xy1].count(xy2)) continue;

                    int x1(xy1 / w), y1(xy1 % w), x2(xy2 / w), y2(xy2 % w);

                    if (x1 < 0 || x1 >= len) continue;
                    if (x2 < 0 || x2 >= len) continue;
                    if (y1 < 0 || y1 >= w) continue;
                    if (y2 < 0 || y2 >= w) continue;

                    if (grid[x1][y1] || grid[x2][y2]) continue;
                    if (i == 2 && (y2 + 1 >= w || grid[x2][y2 + 1])) continue;
                    if (i == 3 && (x2 + 1 >= len || grid[x2 + 1][y2])) continue;

                    if (xy1 == len * w - 2 && xy2 == len * w - 1) return steps;

                    q.push({xy1, xy2});
                    visited[xy1].insert(xy2);
                }
            }

            steps++;
        }

        return -1;
    }
};
