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
    int removeStones(vector<vector<int>>& stones) {
        int n(stones.size());
        StaticUnion uf(n);

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uf.unite(i, j);
        for (int i = 0; i < n; ++i)
            uf.find(i);
        return stones.size() - unordered_set<int>(uf.parents.begin(), uf.parents.end()).size();
    }
};
