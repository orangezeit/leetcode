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
        if (px == py) return true;
        ranks[px] >= ranks[py] ? parents[py] = px : parents[px] = py;
        if (ranks[px] == ranks[py]) ranks[px]++;
        return false;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); ++i)
            edges[i].emplace_back(i);
        sort(edges.begin(), edges.end(),
            [](const auto& e1, const auto& e2){ return e1[2] < e2[2] || e1[2] == e2[2] && e1 < e2; });

        auto mst = [&](int ex=-1, int in=-1) {
            StaticUnion uf(n);
            int cost(0), cnt(0);
            if (in >= 0) {
                cost += edges[in][2];
                uf.unite(edges[in][0], edges[in][1]);
                cnt++;
            }
            for (int i = 0; i < edges.size(); ++i) {
                if (i == ex || uf.unite(edges[i][0], edges[i][1])) continue;
                cost += edges[i][2];
                cnt++;
            }
            return cnt == n - 1 ? cost : INT_MAX;
        };
        const int min_cost = mst();
        vector<int> ans, ans2;
        for (int i = 0; i < edges.size(); ++i) {
            if (mst(i) > min_cost) ans.push_back(edges[i][3]);
            else if (mst(-1, i) == min_cost) ans2.push_back(edges[i][3]);
        }
        return {ans, ans2};
    }
};
