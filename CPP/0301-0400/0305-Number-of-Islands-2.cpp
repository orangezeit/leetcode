class UnionFindDynamic {
private:
    unordered_map<int, int> ranks;
public:
    unordered_map<int, int> parents;

    int find(int i) {
        if (i != parents[i])
            parents[i] = find(parents[i]);
        return parents[i];
    }

    void unite(int i, int j, int& cnt) {
        int pi = find(i);
        int pj = find(j);
        if (pi != pj) cnt--;
        ranks[pi] >= ranks[pj] ? parents[pj] = pi : parents[pi] = pj;
        if (ranks[pi] == ranks[pj]) ranks[pi]++;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        //sort(positions.begin(), positions.end());
        UnionFindDynamic uf;
        vector<int> ans(positions.size());
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int i(0);
        int cnt(0);

        for (const vector<int>& p: positions) {
            if (uf.parents.count(p[0] * n + p[1])) {
                ans[i++] = cnt;
                continue;
            }

            uf.parents[p[0] * n + p[1]] = p[0] * n + p[1];

            for (int i = 0; i < 4; ++i) {
                int newx = p[0] + dirs[i][0];
                int newy = p[1] + dirs[i][1];

                if (newx < 0 || newx >= m || newy < 0 || newy >= n) continue;
                if (uf.parents.count(newx * n + newy))
                    uf.unite(p[0] * n + p[1], newx * n + newy, cnt);
            }

            ans[i++] = ++cnt;
        }
        return ans;
    }
};
