class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> g(n);
        vector<int> colors(n);

        for (const vector<int>& d: dislikes) {
            g[d[1] - 1].emplace_back(d[0] - 1);
            g[d[0] - 1].emplace_back(d[1] - 1);
        }

        function<bool(int, int)> dfs = [&](int i, int c) {
            colors[i] = c;
            for (const int& nxt: g[i]) {
                if (colors[nxt] == c || !colors[nxt] && !dfs(nxt, -c)) return false;
            }
            return true;
        };

        for (int i = 0; i < n; ++i)
            if (!colors[i] && !dfs(i, 1))
                return false;
        return true;
    }
};
