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
    bool equationsPossible(vector<string>& es) {
        StaticUnion uf(26);

        for (const string& e: es)
            if (e[1] == '=')
                uf.unite(e[0] - 'a', e[3] - 'a');

        for (const string& e: es)
            if (e[1] == '!' && uf.find(e[0] - 'a') == uf.find(e[3] - 'a'))
                return false;

        return true;
    }
};
