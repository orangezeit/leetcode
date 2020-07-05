class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> relations(n);

        for (const vector<int>& edge: edges) {
            relations[edge[0] - 1].push_back(edge[1] - 1);
            relations[edge[1] - 1].push_back(edge[0] - 1);
        }

        vector<int> visited(n);
        double ans(0.0);
        bool f(false);

        function<void(int, int, double, bool&)> dfs = [&](int i, int time, double p, bool& found) {
            if (found) return;
            visited[i] = 1;

            if (time == t) {
                if (i == target - 1) {
                    found = true;
                    ans = p;
                }
                return;
            }



            double d(i ? relations[i].size() - 1 : relations[i].size());
            bool canJump(false);
            for (const int& nxt: relations[i]) {
                if (visited[nxt]) continue;
                canJump = true;
                dfs(nxt, time + 1, p / d, found);
                if (found) break;
            }

            if (!canJump && i == target - 1)
                ans = p;
        };

        dfs(0, 0, 1.0, f);
        return ans;
    }
};
