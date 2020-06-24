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
        unordered_map<int, unordered_set<int>> cnts;
        int extra(0);
        unordered_set<int> g;

        for (vector<int>& c: connections) {
            cnts[c[0]].insert(c[1]);
            cnts[c[1]].insert(c[0]);
            if (uf.find(c[0]) != uf.find(c[1])) {
                uf.unite(c[0], c[1]);
            } else {
                extra++;
            }
        }

        for (const int& i: uf.parents)
            g.insert(uf.find(i));

        return extra + 1 < g.size() ? -1 : (g.size() - 1);
    }
};
