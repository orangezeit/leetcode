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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DynamicUnion<string> uf;
        unordered_map<string, string> names;

        for (const vector<string>& account: accounts) {
            names[account[1]] = account[0];
            for (int i = 1; i < account.size(); ++i) {
                if (uf.parents[account[i]].empty())
                    uf.parents[account[i]] = account[i];
                uf.unite(account[1], account[i]);
            }
        }

        unordered_map<string, vector<string>> g;
        for (const auto& [k, v]: uf.parents)
            g[uf.find(k)].emplace_back(k);

        vector<vector<string>> ans(g.size());
        int i = -1;

        for (auto& [k, v]: g) {
            ans[++i].emplace_back(names[k]);
            sort(v.begin(), v.end());
            ans[i].insert(ans[i].end(), v.begin(), v.end());
        }

        return ans;
    }
};
