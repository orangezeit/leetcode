template<typename T>
struct DynamicUnion {
    unordered_map<T, T> parents;
    unordered_map<T, int> ranks;

    constexpr T find(const T& x) {
        if (x != parents[x])
            parents[x] = find(parents[x]);
        return parents[x];
    }

    constexpr void unite(const T& x, const T& y) {
        const T px(find(x)), py(find(y));
        if (px == py) return;
        ranks[px] >= ranks[py] ? parents[py] = px : parents[px] = py;
        if (ranks[px] == ranks[py]) ranks[px]++;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& ps) {
        DynamicUnion<int> uf;
        const int dirs[5] = {0, -1, 0, 1, 0};
        vector<int> ans(ps.size());

        for (int i = 0; i < ps.size(); ++i) {
            int x(ps[i][0]), y(ps[i][1]);
            ans[i] = i ? ans[i - 1] : 0;
            if (uf.parents.count(x * n + y)) continue;

            ans[i]++;
            uf.parents[x * n + y] = x * n + y;

            for (int k = 0; k < 4; ++k) {
                int nx(x + dirs[k]), ny(y + dirs[k + 1]);
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || !uf.parents.count(nx * n + ny)) continue;
                if (uf.find(x * n + y) == uf.find(nx * n + ny)) continue;
                ans[i]--;
                uf.unite(x * n + y, nx * n + ny);
            }
        }
        return ans;
    }
};
