class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& ps, vector<vector<int>>& qs) {
        vector<int> id(n);
        vector<vector<int>> g(n);
        vector<unordered_set<int>> v(n);

        for (const vector<int>& p: ps) {
            id[p[1]]++;
            g[p[0]].push_back(p[1]);
        }

        queue<int> q;
        for (auto i = 0; i < n; i++) {
            if (id[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto x = q.front();
            q.pop();

            for (const int& nxt : g[x]) {
                for (const int& e: v[x])
                    v[nxt].insert(e);
                v[nxt].insert(x);

                if (--id[nxt] == 0)
                    q.push(nxt);
            }
        }

        vector<bool> ans(qs.size());
        for (int i = 0; i < qs.size(); i++) {
            ans[i] = v[qs[i][1]].count(qs[i][0]);
        }

        return ans;
    }
};
