class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        const int m(board.size()), n(board[0].size()), dirs[5] = {0, -1, 0, 1, 0};
        vector<int> erased;
        vector<bool> visited(m * n);

        function<bool(int, int)> check = [&](int x, int y) {
            erased.emplace_back(x * n + y);
            visited[x * n + y] = true;
            bool test(true);
            for (int k = 0; k < 4; ++k) {
                int nx(x + dirs[k]), ny(y + dirs[k + 1]);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || board[nx][ny] == 'X' || visited[nx * n + ny])
                    continue;
                test &= check(nx, ny);
            }
            return test && x > 0 && x < m - 1 && y > 0 && y < n - 1;
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && !visited[i * n + j] && check(i, j)) {
                    for (const int& p: erased)
                        board[p / n][p % n] = 'X';
                }
                erased.clear();
            }
    }
};
