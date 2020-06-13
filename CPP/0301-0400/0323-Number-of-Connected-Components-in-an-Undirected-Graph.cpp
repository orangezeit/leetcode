class UnionFind {
private:
    vector<int> ranks;
public:
    vector<int> parents;
    UnionFind(int n) {
        parents.resize(n);
        ranks.resize(n);
        iota(parents.begin(), parents.end(), 0);
    }

    int find(const int& i) {
        if (i != parents[i])
            parents[i] = find(parents[i]);
        return parents[i];
    }

    void unite(const int& i, const int& j) {
        int pi = find(i);
        int pj = find(j);

        ranks[pi] >= ranks[pj] ? parents[pj] = pi : parents[pi] = pj;
        if (ranks[pi] == ranks[pj]) ranks[pi]++;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf = UnionFind(n);

        for (int i = 0; i < edges.size(); ++i)
            uf.unite(edges[i][0], edges[i][1]);

        for (int i = 0; i < n; ++i)
            uf.find(i);

        unordered_set<int> res(uf.parents.begin(), uf.parents.end());

        return res.size();
    }
};
