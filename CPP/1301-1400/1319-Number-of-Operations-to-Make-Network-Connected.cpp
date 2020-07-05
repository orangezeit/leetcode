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
    int makeConnected(int n, vector<vector<int>>& connections) {
        StaticUnion uf(n);
        int extra(0);
        for (vector<int>& c: connections)
            if (uf.find(c[0]) != uf.find(c[1]))
                uf.unite(c[0], c[1]);
            else
                extra++;
        for (int i = 0; i < n; ++i)
            uf.find(i);
        int group = unordered_set<int>(uf.parents.begin(), uf.parents.end()).size();
        return extra + 1 < group ? -1 : (group - 1);
    }
};
