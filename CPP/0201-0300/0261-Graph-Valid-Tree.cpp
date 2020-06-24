class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_set<int> path;
        unordered_map<int, unordered_set<int>> graph(n);

        for (const vector<int>& e: edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        if (n > 1 && graph.size() < n) return false;

        function<bool(int)> dfs = [&](int curr) {
            if (path.count(curr)) return false;
            path.insert(curr);
            for (const int& nxt: graph[curr]) {
                graph[nxt].erase(curr);
                if (!dfs(nxt)) {
                    path.erase(curr);
                    return false;
                }
            }
            path.erase(curr);
            graph.erase(curr);
            return true;
        };

        return dfs(0) && graph.empty();
    }
};
