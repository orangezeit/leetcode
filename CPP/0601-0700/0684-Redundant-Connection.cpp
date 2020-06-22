struct UnionFind {
    unordered_map<int, int> parents, ranks;
    int find(int x) {
        if (x != parents[x]) parents[x] = find(parents[x]);
        return parents[x];
    }
    void unite(int x, int y) {
        int px(find(x)), py(find(y));
        if (px == py) return;
        if (ranks[px] > ranks[py]) parents[py] = px;
        else if (ranks[px] < ranks[py]) parents[px] = py;
        else {
            parents[py] = px;
            ranks[px]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFind uf;

        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (uf.parents[u] && uf.parents[v] && uf.find(u) == uf.find(v)) return {u, v};
            if (!uf.parents[u])uf.parents[u] = u;
            if (!uf.parents[v])uf.parents[v] = v;
            uf.unite(u, v);
        }

        return {};
    }
};
