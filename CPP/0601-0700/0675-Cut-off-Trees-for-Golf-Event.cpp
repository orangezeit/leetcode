class Solution {
public:
    int bfs(const vector<vector<int>>& forest, const int& curr, const int& target, const int& m, const int& n) {
        int steps(0);
        vector<vector<int>> visited(m, vector<int>(n));
        queue<int> q;
        q.emplace(curr);
        int dirs[5] = {0, -1, 0, 1, 0};

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                if (q.front() == target) return steps;

                int x(q.front() / n), y(q.front() % n);
                q.pop();

                for (int i = 0; i < 4; ++i) {
                    int nx(x + dirs[i]), ny(y + dirs[i + 1]);
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (!forest[nx][ny] || visited[nx][ny]) continue;
                    q.emplace(nx * n + ny);
                    visited[nx][ny] = 1;
                }
            }
            ++steps;
        }

        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        const int m(forest.size()), n(forest[0].size());
        if (!forest[0][0]) return -1;

        vector<vector<int>> trees(m * n, vector<int>(2));
        int sz(0);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (forest[i][j] > 1) {
                    trees[sz][0] = forest[i][j];
                    trees[sz][1] = i * n + j;
                    sz++;
                }

        trees.resize(sz);
        sort(trees.begin(), trees.end());
        int k(0), curr(0), ans(0);

        while (k < trees.size()) {
            int steps = bfs(forest, curr, trees[k][1], m, n);
            if (steps == -1) return -1;
            ans += steps;
            curr = trees[k++][1];
            //k++;
        }

        return ans;
    }
};
