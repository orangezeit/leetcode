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
    int largestComponentSize(vector<int>& A) {
        int n(A.size());
        int m(*max_element(A.begin(), A.end()));
        vector<bool> is_c(m + 1);
        vector<int> ps;

        for (int i = 2; i <= m; ++i) {
            if (!is_c[i])
                ps.push_back(i);
            for (int j = 0; j < ps.size() && ps[j] * i <= m; ++j) {
                is_c[i * ps[j]] = true;
                if (i % ps[j] == 0) break;
            }
        }

        set<int> pps(ps.begin(), ps.end());
        unordered_map<int, vector<int>> factors;
        StaticUnion uf(n);

        for (int i = 0; i < n; ++i) {
            if (pps.count(A[i])) {
                factors[A[i]].emplace_back(i);
                uf.unite(factors[A[i]].front(), factors[A[i]].back());
                continue;
            }

            int t(A[i]);

            for (const int& p: ps) {
                if (p > t) break;
                if (t % p == 0) {
                    factors[p].emplace_back(i);
                    uf.unite(factors[p].front(), factors[p].back());
                    while (t % p == 0) t /= p;
                }
            }
        }

        unordered_map<int, int> g;
        int ans(1);
        for (int i = 0; i < n; ++i)
            ans = max(ans, ++g[uf.find(i)]);
        return ans;
    }
};
