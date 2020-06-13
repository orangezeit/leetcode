class UnionFind {
private:
    unordered_map<int, int> ranks;
public:
    unordered_map<int, int> parents;

    int find(int i) {
        if (i != parents[i])
            parents[i] = find(parents[i]);
        return parents[i];
    }

    void unite(int i, int j) {
        int pi = find(i);
        int pj = find(j);

        ranks[pi] >= ranks[pj] ? parents[pj] = pi : parents[pi] = pj;
        if (ranks[pi] == ranks[pj]) ranks[pi]++;
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        priority_queue<pair<int, int>> pq;
        int m = A.size();
        int n = A[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                pq.push({A[i][j], i * n + j});

        UnionFind uf;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        //uf.parents[0] = 0;
        //uf.parents[m * n - 1] = m * n - 1;

        while (!pq.empty()) {
            int val = pq.top().first;
            int xy = pq.top().second;

            pq.pop();

            uf.parents[xy] = xy;

            for (int i = 0; i < 4; ++i) {
                int x = xy / n + dirs[i][0];
                int y = xy % n + dirs[i][1];

                if (x < 0 || x >= m || y < 0 || y >= n) continue;
                if (!uf.parents.count(x * n + y)) continue;
                uf.unite(xy, x * n + y);
            }
            if (uf.parents.count(0) && uf.parents.count(m * n - 1))
            if (uf.find(0) == uf.find(m * n - 1))
                return val;
        }

        return -1;
    }
};
