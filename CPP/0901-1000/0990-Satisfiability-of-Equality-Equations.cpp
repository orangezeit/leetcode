class UnionFind {
private:
    unordered_map<int, int> parents, ranks;
public:
    UnionFind(int n) {
        for (int i = 0; i < n; ++i) {
            parents[i] = i;
            ranks[i] = 0;
        }
    }

    int find(int x) {
        if (x != parents[x])
            parents[x] = find(parents[x]);
        return parents[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (ranks[px] > ranks[py])
            parents[py] = px;
        else if (ranks[px] < ranks[py])
            parents[px] = py;
        else {
            parents[py] = px;
            ranks[px]++;
        }
    }
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UnionFind u = UnionFind(26);

        for (int i = 0; i < equations.size(); ++i)
            if (equations[i][1] == '=')
                u.unite(equations[i][0] - 'a', equations[i][3] - 'a');

        for (int i = 0; i < equations.size(); ++i)
            if (equations[i][1] == '!')
                if (u.find(equations[i][0] - 'a') == u.find(equations[i][3] - 'a'))
                    return false;

        return true;
    }
};
