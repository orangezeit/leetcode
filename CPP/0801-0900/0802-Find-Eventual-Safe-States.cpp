class Solution {
public:
    enum state {UNKNOWN, VISITING, SAFE, UNSAFE};
    state dfs(const vector<vector<int>>& g, int cur, vector<state>& states) {
        if (states[cur] == VISITING) return UNSAFE;
        if (states[cur] != UNKNOWN) return states[cur];
        states[cur] = VISITING;
        for (const int& e: g[cur])
            if (dfs(g, e, states) == UNSAFE)
                return states[cur] = UNSAFE;
        return states[cur] = SAFE;
    }

    vector<int> eventualSafeNodes(const vector<vector<int>>& graph) {
        vector<state> states(graph.size(), UNKNOWN);
        vector<int> ans;
        for (int i = 0; i < graph.size(); ++i)
            if (dfs(graph, i, states) == SAFE)
                ans.push_back(i);
        return ans;
    }
};
