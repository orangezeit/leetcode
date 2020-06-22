class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dirs[5] = {0, -1, 0, 1, 0};

        queue<int> q;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (matrix[i][j])
                    matrix[i][j] = m + n + 1;
                else
                    q.push(i * n + j);

        while(!q.empty()) {
            int x(q.front() / n), y(q.front() % n);
            q.pop();

            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || matrix[nx][ny] <= matrix[x][y] + 1) continue;
                matrix[nx][ny] = matrix[x][y] + 1;
                q.push(nx * n + ny);
            }
        }

        return matrix;
    }
};
