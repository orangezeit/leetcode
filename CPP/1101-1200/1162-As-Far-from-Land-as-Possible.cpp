class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n(grid.size()), ans(-1), dirs[5] = {0, 1, 0, -1, 0};
        queue<int> q;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    q.push(i * n + j);

        if (q.size() == n * n) return -1;

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int xy = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int nx(xy / n + dirs[k]), ny(xy % n + dirs[k + 1]);
                    if (nx < 0 || nx >= n || ny < 0 || ny >=n || grid[nx][ny]) continue;
                    grid[nx][ny] = 1;
                    q.push(nx * n + ny);
                }
            }
            ans++;
        }

        return ans;
    }
};
