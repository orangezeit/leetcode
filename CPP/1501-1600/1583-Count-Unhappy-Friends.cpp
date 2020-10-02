class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int closes[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n - 1; ++j)
                closes[i][preferences[i][j]] = n - j;

        vector<int> unhappy(n);
        for (int i = 0; i < n / 2; ++i) {
            int x = pairs[i][0], y = pairs[i][1];
            for (int j = i + 1; j < n / 2; ++j) {
                int u = pairs[j][0], v = pairs[j][1];
                if (closes[x][u] > closes[x][y] && closes[u][x] > closes[u][v])
                    unhappy[x] = unhappy[u] = 1;
                swap(x, y);
                if (closes[x][u] > closes[x][y] && closes[u][x] > closes[u][v])
                    unhappy[x] = unhappy[u] = 1;
                swap(u, v);
                if (closes[x][u] > closes[x][y] && closes[u][x] > closes[u][v])
                    unhappy[x] = unhappy[u] = 1;
                swap(x, y);
                if (closes[x][u] > closes[x][y] && closes[u][x] > closes[u][v])
                    unhappy[x] = unhappy[u] = 1;
            }
        }
        return accumulate(unhappy.begin(), unhappy.end(), 0);
    }
};
