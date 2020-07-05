class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> ans(n, -1);
        int steps = 1;
        unordered_map<int, unordered_set<int>> re, be, rv, bv;

        for (const vector<int>& e: red_edges)
            re[e[0]].insert(e[1]);

        for (const vector<int>& e: blue_edges)
            be[e[0]].insert(e[1]);

        queue<pair<int, int>> q;
        q.push({0, 0});
        ans[0] = 0;

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                int curr = q.front().first;
                int color = q.front().second;
                q.pop();

                if (color != 1) {
                    for (const auto& e: re[curr]) {
                        if (rv[curr].count(e)) continue;
                        q.push({e, 1});
                        if (ans[e] == -1) ans[e] = steps;
                        rv[curr].insert(e);
                    }
                }

                if (color != -1) {
                    for (const auto& e: be[curr]) {
                        if (bv[curr].count(e)) continue;
                        q.push({e, -1});
                        if (ans[e] == -1) ans[e] = steps;
                        bv[curr].insert(e);
                    }
                }
            }
            ++steps;
        }


        return ans;
    }
};
