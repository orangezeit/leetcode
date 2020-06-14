class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n(flights.size()), d(days[0].size()), ans(0);
        vector<int> dp(n);
        dp[0] = 1;

        for (int i = 0; i < d; ++i) {
            vector<int> temp(n);
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    // day i, prev city j, curr city k
                    if (dp[j] && (j == k || flights[j][k]))
                        ans = max(ans, temp[k] = max(temp[k], dp[j] + days[k][i]));
            swap(dp, temp);
        }

        return ans - 1;
    }
};
