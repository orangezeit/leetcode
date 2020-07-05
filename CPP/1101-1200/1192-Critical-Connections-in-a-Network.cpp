class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;
        vector<int> jump(n, -1);
        vector<vector<int>> ans;

        for (const vector<int>& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        function<int(const int&, const int&, const int&)> dfs = [&](const int& curr, const int& parent, const int& level) {
            jump[curr] = level;
            for (int next: g[curr]) {
                if (next == parent) continue;
                jump[curr] = min(jump[curr], jump[next] == -1 ? dfs(next, curr, level + 1) : jump[next]);
            }

            if (jump[curr] == level && curr)
                ans.push_back({parent, curr});
            return jump[curr];
        };
        dfs(0, -1, 0);
        //for (int i: jump) cout << i << ' ';
        return ans;
    }
};
