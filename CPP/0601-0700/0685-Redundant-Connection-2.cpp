class Solution {
public:
    int find(int node, vector<int>& roots) {
        return node == roots[node] ? node : roots[node] = find(roots[node], roots);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n(edges.size());
        vector<int> parents(n + 1), roots(n + 1), sizes(n + 1), ans1, ans2;
        for (vector<int>& edge: edges) {
            int u(edge[0]), v(edge[1]);
            // a node has two parents
            if (parents[v]) {
                ans1 = {parents[v], v};
                ans2 = edge;

                edge[0] = edge[1] = -1;
            }
            parents[v] = u;
        }
        for (const vector<int>& edge: edges) {
            int u(edge[0]), v(edge[1]);
            if (u < 0) continue;

            if (!roots[u]) roots[u] = u;
            if (!roots[v]) roots[v] = v;
            int pu(find(u, roots)), pv(find(v, roots));

            if (pu == pv) return ans1.empty() ? edge : ans1;
            if (sizes[pv] > sizes[pu]) swap(pu, pv);
            roots[pv] = pu;
            sizes[pu] += sizes[pv];
        }
        return ans2;
    }
};
