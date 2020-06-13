class Solution {
public:
    unordered_map<int, unordered_set<int>> g;
    unordered_set<int> rec;
    bool dfs(int curr, const int& dest) {
        int test(true);
        for (const auto& next: g[curr]) {
            if (rec.count(next)) return false;
            rec.insert(next);
            test &= dfs(next, dest);
            rec.erase(next);
            if (!test) return false;
        }
        if (g[curr].empty()) test &= curr == dest;
        return test;
    }
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {


        for (const vector<int>& e: edges)
            g[e[0]].insert(e[1]);
        return dfs(source, destination);
    }
};
