class UnionFindStatic {
private:
    vector<int> ranks;
public:
    vector<int> parents;
    UnionFindStatic(int n) {
        parents.resize(n);
        ranks.resize(n);
        iota(parents.begin(), parents.end(), 0);
    }

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
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].length();
        //cout << m << n << endl;
        int c = 4 * m * n;
        UnionFindStatic uf = UnionFindStatic(c);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //cout << i << j << endl;
                int base = 4 * (j + i * n);
                //  + (0, 1, 2, 3)
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

        unordered_set<int> regions;
        for (const int& p: uf.parents) regions.insert(uf.find(p));
        return regions.size();
    }
};
