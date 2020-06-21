class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> paths;

        function<void(int)> dfs = [&](int cur) {
            path.emplace_back(cur);
            if (graph[cur].empty()) paths.emplace_back(path);
            for (const int& nxt: graph[cur])
                dfs(nxt);
            path.pop_back();
        };

        dfs(0);

        return paths;
    }
};
