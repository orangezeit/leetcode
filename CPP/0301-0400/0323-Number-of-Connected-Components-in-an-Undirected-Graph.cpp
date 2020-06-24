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
    int countComponents(int n, vector<vector<int>>& edges) {
        StaticUnion uf(n);

        for (const vector<int>& e: edges)
            uf.unite(e[0], e[1]);

        for (int i = 0; i < n; ++i)
            uf.find(i);

        return unordered_set<int>(uf.parents.begin(), uf.parents.end()).size();
    }
};
