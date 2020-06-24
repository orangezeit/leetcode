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
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(),
             [](const vector<int>& a, const vector<int>& b) {return a[2] < b[2];});

        StaticUnion uf(n);
        int costs(0);

        for (vector<int>& c: connections)
            if (uf.find(c[0] - 1) != uf.find(c[1] - 1)) {
                costs += c[2];
                uf.unite(c[0] - 1, c[1] - 1);
            }

        for (const int& i: uf.parents)
            if (uf.find(0) != uf.find(i))
                return -1;
        return costs;
    }
};
