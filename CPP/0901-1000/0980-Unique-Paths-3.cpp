class Solution {
public:
    int m, n;
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> g;
    void traverse(int i, int j, const int& empties, unordered_set<int> path, int& cnt) {
        if (g[i][j] == 2) {
            if (path.size() - 2 == empties) cnt++;
        } else {
            for (int k = 0; k < 4; ++k) {
                int newi = i + dirs[k][0];
                int newj = j + dirs[k][1];

                if (newi < 0 || newi >= m || newj < 0 || newj >= n) continue;
                if (path.find(newi * n + newj) != path.end()) continue;
                if (g[newi][newj] == -1) continue;

                path.insert(newi * n + newj);
                traverse(newi, newj, empties, path, cnt);
                path.erase(newi * n + newj);
            }
            //cout << 1;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        g = grid;
        int empties(0);
        int ci, cj;
        int cnt(0);

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (!grid[i][j]) empties++;
                else if (grid[i][j] == 1) {
                    ci = i;
                    cj = j;
                }
        unordered_set<int> path;
        path.insert(ci * n + cj);
        traverse(ci, cj, empties, path, cnt);

        return cnt;
    }
};
