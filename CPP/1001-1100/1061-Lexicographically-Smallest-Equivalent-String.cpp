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
    string smallestEquivalentString(string A, string B, string S) {
        StaticUnion uf(26);

        for (int i = 0; i < A.length(); ++i)
            uf.unite(A[i] - 'a', B[i] - 'a');

        for (int i = 0; i < 26; ++i)
            uf.find(i);

        for (char& c: S)
            for (int i = 0; i < 26; ++i)
                if (uf.parents[i] == uf.parents[c - 'a']) {
                    c = 'a' + i;
                    break;
                }
        return S;
    }
};
