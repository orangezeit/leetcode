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
    int numSimilarGroups(vector<string>& a) {
        int n(a.size());
        StaticUnion uf(n);

        auto similar = [](const string& s, const string& t) {
            int n = 0;

            for (int i = 0; i < s.length(); ++i)
                if (s[i] != t[i])
                    if (++n > 2)
                        return false;

            return true;
        };

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (uf.find(i) != uf.find(j) && similar(strs[i], strs[j]))
                    uf.unite(i, j);

        for (int i = 0; i < n; ++i)
            uf.find(i);

        return unordered_set<int>(uf.parents.begin(), uf.parents.end()).size();
    }
};
