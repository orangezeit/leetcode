class Solution {
public:
    int minReorder(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> g(n);
        for (const vector<int>& e: edges) {
            g[e[0]].push_back({e[1], 1});
            g[e[1]].push_back({e[0], 0});
        }
        queue<int> q({0});
        vector<bool> visited(n);
        int ans(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;

            for (const auto& [nxt, w]: g[cur]) {
                if (visited[nxt]) continue;
                ans += w;
                q.push(nxt);
            }
        }

        return ans;
    }
};
