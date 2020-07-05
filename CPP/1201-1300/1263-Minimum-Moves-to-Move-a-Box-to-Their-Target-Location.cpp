class Solution {
public:
    int m, n;
    int dirs[5] = {0, -1, 0, 1, 0};

    bool canPush(vector<vector<char>>& grid, int bx, int by) {
        if (bx < 0 || bx >= m || by < 0 || by >= n) return false;
        if (grid[bx][by] == '#') return false;
        return true;
    }

    bool canReach(vector<vector<char>>& grid, int bx, int by, int px, int py, int dx, int dy) {
        dx += bx;
        dy += by;
        if (dx < 0 || dx >= m || dy < 0 || dy >= n) return false;
        if (grid[dx][dy] == '#') return false;

        queue<int> q;
        q.push(100 * px + py);
        vector<vector<int>> visited(m, vector<int>(n));
        visited[px][py] = 1;

        while (!q.empty()) {
            int x(q.front() / 100), y(q.front() % 100);
            q.pop();
            if (x == dx && y == dy) return true;
            for (int i = 0; i < 4; ++i) {
                int nx(x + dirs[i]), ny(y + dirs[i + 1]);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (grid[nx][ny] == '#') continue;
                if (nx == bx && ny == by) continue;
                if (visited[nx][ny]) continue;
                q.push(nx * 100 + ny);
                visited[nx][ny] = 1;
            }
        }

        return false;
    }

    int minPushBox(vector<vector<char>>& grid) {
        int bx, by, px, py, tx, ty;
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 'B') {
                    bx = i;
                    by = j;
                } else if (grid[i][j] == 'T') {
                    tx = i;
                    ty = j;
                } else if (grid[i][j] == 'S') {
                    px = i;
                    py = j;
                }
            }
        }

        queue<vector<int>> q;
        q.push({bx, by, px, py});
        unordered_set<int> states; // bx * 1000000 + by * 10000 + px * 100 + py
        int steps(0);


        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                vector<int> loc = q.front();
                q.pop();
                if (loc[0] == tx && loc[1] == ty) return steps;
                for (int i = 0; i < 4; ++i) {
                    if (canReach(grid, loc[0], loc[1], loc[2], loc[3], dirs[i], dirs[i+1]) &&
                        canPush(grid, loc[0]-dirs[i], loc[1]-dirs[i+1])) {
                        //cout << "---";
                        int nbx(loc[0] - dirs[i]), nby(loc[1] - dirs[i+1]), npx(loc[0]), npy(loc[1]);
                        if (states.count(nbx * 1000000 + nby * 10000 + npx * 100 + npy)) continue;
                        states.insert(nbx * 1000000 + nby * 10000 + npx * 100 + npy);
                        q.push({nbx, nby, npx, npy});
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};
