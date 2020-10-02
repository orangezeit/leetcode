class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        vector<int> dp(n);
        vector<string> paths(n);
        // build the graph
        vector<vector<int>> g(n);
        for (const vector<int>& road: roads) {
            g[road[0]].emplace_back(road[1]);
            g[road[1]].emplace_back(road[0]);
        }
        // buttom-up dp
        for (const string& city: targetPath) {
            vector<int> dp2(n, 100);
            vector<string> paths2(n);
            for (int i = 0; i < n; ++i)
                for (const int& j: g[i])
                    if (dp2[j] > dp[i] + (city != names[j])) {
                        dp2[j] = dp[i] + (city != names[j]);
                        paths2[j] = paths[i];
                        paths2[j] += j;
                    }
            swap(dp, dp2);
            swap(paths, paths2);
        }
        string& str = paths[min_element(dp.begin(), dp.end()) - dp.begin()];
        return vector<int>(str.begin(), str.end());
    }
};
