class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans(0);
        vector<vector<int>> mat(n);

        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1)
                mat[manager[i]].push_back(i);
        }

        function<void(int, int)> dfs = [&](int x, int t){
            for (int& i: mat[x]) {
                dfs(i, t + informTime[x]);
            }
            ans = max(ans, t);
        };
        dfs(headID, 0);
        return ans;
    }
};
