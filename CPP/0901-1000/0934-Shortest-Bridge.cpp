class Solution {
public:
    const int dirs[5] = {0, 1, 0, -1, 0};

    void floodFill(int x, int y, vector<vector<int>>& A, vector<pair<int, int>>& land, int n, int m) {
        A[x][y] = 2;
        int num(0);

        for (int k = 0; k < 4; ++k) {
            int nx(x + dirs[k]), ny(y + dirs[k + 1]);
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || !A[nx][ny]) continue;
            num++;
            if (A[nx][ny] == 1)
                floodFill(nx, ny, A, land, n, m);
        }

        if (num != 4)
            land.push_back({x, y});

    }

    int shortestBridge(vector<vector<int>>& A) {
        const int n(A.size()), m(A[0].size());
        vector<pair<int, int>> land1, land2;
        bool one = true;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (A[i][j] == 1) {
                    floodFill(i, j, A, land1.empty() ? land1 : land2, n, m);
                    if (!land2.empty()) break;
                }

        int len = n + m - 1;
        for (const auto& [x1, y1]: land1)
            for (const auto& [x2, y2]: land2)
                len = min(len, abs(x2 - x1) + abs(y2 - y1) - 1);
        return len;
    }
};
