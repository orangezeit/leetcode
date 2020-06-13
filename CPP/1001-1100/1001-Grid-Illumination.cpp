class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> h, v, d1, d2;
        for (const vector<int>& lamp: lamps) {
            int x = lamp[0];
            int y = lamp[1];
            int mn1 = min(x, y);
            int mn2 = min(x, n - 1 - y);

            h[x].insert(y);
            v[y].insert(x);
            d1[x + y - 2 * mn1 + (x == mn1 ? 0 : n)].insert(mn1);
            d2[x + y].insert(mn2);
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int qx = queries[i][0], qy = queries[i][1], mn = min(qx, qy);
            int t1 = qx + qy - 2 * mn + (qx == mn ? 0 : n), t2 = qx + qy;

            if (h.count(qx) || v.count(qy) || d1.count(t1) || d2.count(t2))
                ans[i] = 1;

            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++ dy) {
                    int nx(qx + dx), ny(qy + dy);
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                    int mn1 = min(nx, ny), mn2 = min(nx, n - 1 - ny);
                    int k1 = nx + ny - 2 * mn1 + (nx == mn1 ? 0 : n);
                    int k2 = nx + ny;

                    if (h.count(nx) && h[nx].count(ny)) {
                        h[nx].erase(ny);
                        if (h[nx].empty()) h.erase(nx);
                    }

                    if (v.count(ny) && v[ny].count(nx)) {
                        v[ny].erase(nx);
                        if (v[ny].empty()) v.erase(ny);
                    }

                    if (d1.count(k1) && d1[k1].count(mn1)) {
                        d1[k1].erase(mn1);
                        if (d1[k1].empty()) d1.erase(k1);
                    }

                    if (d2.count(k2) && d2[k2].count(mn2)) {
                        d2[k2].erase(mn2);
                        if (d2[k2].empty()) d2.erase(k2);
                    }
                }
            }
        }
        return ans;
    }
};
