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
        sort(A.begin(), A.end());
        int n(A.size()), m(A.back());
      bool is_c[m + 1] = {};
      vector<int> ps;
      for (int i = 2; i <= m; ++i) {
        if (!is_c[i]) ps.emplace_back(i);
        for (int j = 0; j < ps.size() && ps[j] * i <= m; ++j) {
          is_c[i * ps[j]] = true;
          if (i % ps[j] == 0) break;
        }
      }
      vector<int> factors(ps.size(), -1);
      StaticUnion uf(n);
      for (int i = 0; i < n; ++i) {
        if (A[i] == 1) continue;
        if (!is_c[A[i]]) {
          factors[lower_bound(ps.begin(), ps.end(), A[i]) - ps.begin()] = i;
          continue;
        }
        for (int j = 0; j < ps.size(); ++j) {
          if (ps[j] > A[i]) break;
          if (A[i] % ps[j] == 0) {
            if (factors[j] == -1)
              factors[j] = i;
            else
              uf.unite(factors[j], i);
            while (A[i] % ps[j] == 0) A[i] /= ps[j];
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
