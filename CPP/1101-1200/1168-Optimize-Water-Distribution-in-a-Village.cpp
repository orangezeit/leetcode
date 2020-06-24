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
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        StaticUnion uf(n);
        sort(pipes.begin(), pipes.end(),
             [](const vector<int>& p1, const vector<int>& p2){return p1[2] < p2[2];});
        int total(0);

        for (const vector<int>& pipe: pipes) {
            int a(pipe[0] - 1), b(pipe[1] - 1), c(pipe[2]);
            int pa(uf.find(a)), pb(uf.find(b));
            if (pa != pb) {
                int mw = min(wells[pa], wells[pb]);
                if (wells[pa] + wells[pb] > mw + c) {
                    uf.unite(a, b);
                    wells[pa] = wells[pb] = mw;
                    total += c;
                }
            }
        }

        unordered_set<int> visited;
        for (int i = 0; i < n; ++i) {
            int p = uf.find(i);
            if (!visited.count(p)) {
                total += wells[p];
                visited.insert(p);
            }
        }
        return total;
    }
};
