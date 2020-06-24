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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        StaticUnion uf(n);
        sort(logs.begin(), logs.end());
        for (const vector<int>& log: logs) {
            uf.unite(log[1], log[2]);
            int c(uf.find(0)), k(0);
            for (k = 0; k < n; ++k)
                if (c != uf.find(k)) break;
            if (k == n) return log[0];
        }
        return -1;
    }
};
