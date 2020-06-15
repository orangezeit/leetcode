class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        vector<vector<int>> tree(n);

        for (const vector<int>& e: edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        function<int(int, int)> dfs = [&](int curr, int parent) {
			// int: distance we accumulate so far
            int ans(0);

            for (const int& child: tree[curr]) {
                if (child == parent) continue;
                int prev = dfs(child, curr);
                if (prev > 0 || hasApple[child]) ans += prev + 2;
            }
            return ans;
        };

        return dfs(0, -1);
    }
};
