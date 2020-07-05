class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        const int m(grid.size()), n(grid[0].size());
        const int dirs[5] = {0, 1, 0, -1, 0};  // right, down, left, up
        const int rules[6][2] = {{0, 2}, {1, 3}, {1, 2}, {0, 1}, {2, 3}, {0, 3}};

        queue<int> q;
        q.push(0);
        vector<int> visited(m * n);

        while (!q.empty()) {
            int x(q.front() / n), y(q.front() % n), d(grid[x][y] - 1);
            visited[q.front()] = 1;
            q.pop();

            if (x == m - 1 && y == n - 1) return true;

            for (const int& i: rules[d]) {
                int nx(x + dirs[i]), ny(y + dirs[i + 1]);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                if (visited[nx * n + ny]) continue;
                int nd(grid[nx][ny] - 1);
                if (rules[nd][0] != (i + 2) % 4 && rules[nd][1] != (i + 2) % 4) continue;
                q.push(nx * n + ny);
            }
        }

        return false;
    }
};
