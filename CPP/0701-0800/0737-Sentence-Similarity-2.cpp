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
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        DynamicUnion<string> uf;
        for (const vector<string>& p: pairs) {
            if (uf.parents[p[0]].empty()) uf.parents[p[0]] = p[0];
            if (uf.parents[p[1]].empty()) uf.parents[p[1]] = p[1];
            uf.unite(p[0], p[1]);
        }

        for (const auto& [k, v]: uf.parents)
            uf.find(k);

        for (int i = 0; i < words1.size(); ++i) {
            if (uf.parents[words1[i]] != uf.parents[words2[i]])
                return false;
        }
        return true;
    }
};
