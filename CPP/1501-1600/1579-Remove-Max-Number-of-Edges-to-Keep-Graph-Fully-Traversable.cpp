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
    bool unite(const int& x, const int& y) {
        int px(find(x)), py(find(y));
        if (px == py) return false;
        ranks[px] >= ranks[py] ? parents[py] = px : parents[px] = py;
        if (ranks[px] == ranks[py]) ranks[px]++;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        StaticUnion g1(n), g2(n);
        int ans(0);
        for (vector<int>& edge: edges) {
            edge[1]--;edge[2]--;
            if (edge[0] != 3) continue;
            if (!g1.unite(edge[1], edge[2])) ans++;
            g2.unite(edge[1], edge[2]);
        }
        for (vector<int>& edge: edges) {
            if (edge[0] == 1 && !g1.unite(edge[1], edge[2])) ans++;
            if (edge[0] == 2 && !g2.unite(edge[1], edge[2])) ans++;
        }
        int c1(g1.find(0)), c2(g2.find(0));
        for (int i = 1; i < n; ++i)
            if (c1 != g1.find(i) || c2 != g2.find(i))
                return -1;

        return ans;
    }
};
