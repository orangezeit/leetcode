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
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].length();
        StaticUnion uf(4 * m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int base = 4 * (j + i * n);

                if (grid[i][j] != '/') {
                    uf.unite(base, base + 3);
                    uf.unite(base + 1, base + 2);
                }

                if (grid[i][j] != '\\') {
                    uf.unite(base, base + 1);
                    uf.unite(base + 3, base + 2);
                }
                if (i) uf.unite(base, base - 4 * n + 2);
                if (j) uf.unite(base + 1, base - 1);

            }
        }

        for (int& i: uf.parents) i = uf.find(i);
        return unordered_set<int>(uf.parents.begin(), uf.parents.end()).size();
    }
};
