class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> g(n);
        for (const auto& e: edges) {
            g[e[0]].emplace_back(e[1]);
            g[e[1]].emplace_back(e[0]);
        }

        vector<int> ans(n);

        function<vector<int>(int, int)> dfs = [&](int i, int p) {
            vector<int> letters(26);
            for (const int& nxt: g[i]) {
                if (nxt == p) continue;
                vector<int> tmp = dfs(nxt, i);
                for (int i = 0; i < 26; ++i)
                    letters[i] += tmp[i];
            }
            letters[labels[i] - 'a']++;
            ans[i] = letters[labels[i] - 'a'];
            return letters;
        };
        dfs(0, -1);
        return ans;
    }
};
