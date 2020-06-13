class UnionFind {
public:
    vector<int> m;

    UnionFind(int n) {
        m.resize(n);
        iota(m.begin(), m.end(), 0);
    }

    int find(int i) {
        return i == m[i] ? m[i] : m[i] = find(m[i]);
    }

    void unite(int i, int j) {
        m[find(i)] = find(j);
    }
};

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        UnionFind uf = UnionFind(n);

        //for (int i = 1; i <= n; ++i) uf.m[i] = i;
        unordered_map<int, int> costs;

        for (int i = 0; i < wells.size(); ++i)
            costs[i] = wells[i];

        sort(pipes.begin(), pipes.end(), [](const vector<int>& p1, const vector<int>& p2){return p1[2] < p2[2];});
        int total(0);

        for (const vector<int>& pipe: pipes) {
            int a(pipe[0] - 1), b(pipe[1] - 1), c(pipe[2]);
            int pa(uf.find(a)), pb(uf.find(b));
            if (pa != pb) {
                int minWell = min(costs[pa], costs[pb]);
                int costSeparate = costs[pa] + costs[pb];
                if (costs[pa] + costs[pb] > minWell + c) {
                    uf.unite(a, b);
                    costs[pb] = minWell;
                    total += c;
                }
            }
        }
        //cout << total << endl;
        unordered_set<int> visited;
        for (int i = 0; i < n; ++i) {
            int p = uf.find(i);
            //cout << "p" << p << endl;
            if (!visited.count(p)) {
                total += costs[p];
                visited.insert(p);
            }
        }
        return total;
    }
};
