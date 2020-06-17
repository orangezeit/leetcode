struct UnionFind {
    vector<int> parents, ranks;
    UnionFind(int n) {
        parents.resize(n);
        ranks.resize(n);
        for (int i = 0; i < n; ++i) parents[i] = i;
    }
    int find(int x) {
        if (x != parents[x]) parents[x] = find(parents[x]);
        return parents[x];
    }
    void unite(int x, int y) {
        int px(find(x)), py(find(y));
        if (px == py) return;
        if (ranks[px] > ranks[py]) parents[py] = px;
        else if (ranks[px] < ranks[py]) parents[px] = py;
        else {
            parents[py] = px;
            ranks[px]++;
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf(stones.size());

        for (int i = 0; i < stones.size() - 1; ++i)
            for (int j = i + 1; j < stones.size(); ++j)
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    uf.unite(i, j);

        unordered_set<int> rec;
        for (const int& i: uf.parents) rec.insert(uf.find(i));
        return stones.size() - rec.size();
    }
};
