class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1);
        //int d = days[0];
        int k = 0;
        for (int i = 1; i < dp.size(); ++i)
            if (i < days[k]) {
                dp[i] = dp[i - 1];
            } else {
                dp[i] = min(min(dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1]), dp[max(0, i - 30)] + costs[2]);
                k++;
            }
        return dp.back();
    }
};
