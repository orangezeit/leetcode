class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> roadmap(n);
        for (const vector<int>& f: flights)
            roadmap[f[0]].emplace_back(make_pair(f[1], f[2]));

        int ans(INT_MAX);
        bool s[100] = {};
        k++;

        function<void(int, int)> dfs = [&](int cur, int cost) {
            if (cur == dst) {
                ans = min(cost, ans);
                return;
            }
            k--;
            s[cur] = true;
            for (const auto& [nxt, c]: roadmap[cur])
                if (!s[nxt] && cost + c < ans && k >= 0)
                    dfs(nxt, cost + c);
            k++;
            s[cur] = false;
        };

        dfs(src, 0);

        return ans == INT_MAX ? -1 : ans;
    }
};
