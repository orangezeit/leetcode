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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DynamicUnion<int> uf;

        for (const vector<int>& e: edges) {
            if (uf.parents[e[0]] && uf.parents[e[1]] && uf.find(e[0]) == uf.find(e[1]))
                return {e[0], e[1]};
            if (!uf.parents[e[0]]) uf.parents[e[0]] = e[0];
            if (!uf.parents[e[1]]) uf.parents[e[1]] = e[1];
            uf.unite(e[0], e[1]);
        }

        return {};
    }
};
