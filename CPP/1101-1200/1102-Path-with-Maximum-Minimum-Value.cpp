struct StaticUnion {
    vector<int> parents, ranks;
    StaticUnion(int n) : parents(n), ranks(n) {
        iota(parents.begin(), parents.end(), 0);
    }

    int find(const int& x) {
        if (x != parents[x])
            parents[x] = find(parents[x]);
        return parents[x];
    }

    void unite(const int& x, const int& y) {
        int px(find(x)), py(find(y));
        if (px == py) return;
        ranks[px] >= ranks[py] ? parents[py] = px : parents[px] = py;
        if (ranks[px] == ranks[py]) ranks[px]++;
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        priority_queue<pair<int, int>> pq;
        const int m(A.size()), n(A[0].size()), dirs[5] = {0, -1, 0, 1, 0};
        vector<bool> visited(m * n);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                pq.push({A[i][j], i * n + j});

        StaticUnion uf(m * n);

        while (!pq.empty()) {
            int v(pq.top().first), xy(pq.top().second);
            visited[xy] = true;
            pq.pop();

            uf.parents[xy] = xy;

            for (int i = 0; i < 4; ++i) {
                int x = xy / n + dirs[i];
                int y = xy % n + dirs[i + 1];

                if (x < 0 || x >= m || y < 0 || y >= n || !visited[x * n + y]) continue;
                uf.unite(xy, x * n + y);
            }

            if (visited[0] && visited[m * n - 1] && uf.find(0) == uf.find(m * n - 1))
                return v;
        }

        return -1;
    }
};
