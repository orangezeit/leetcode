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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n(s.length());
        StaticUnion uf(n);

        for (const vector<int>& pair: pairs)
            uf.unite(pair[0], pair[1]);

        unordered_map<int, vector<int>> rec;

        for (int i = 0; i < n; ++i)
            rec[uf.find(i)].emplace_back(i);

        for (const auto& [k, v]: rec) {
            string t;
            for (const int& i: v) t += s[i];
            sort(t.begin(), t.end());
            for (int i = 0; i < v.size(); ++i) s[v[i]] = t[i];
        }

        return s;
    }
};
