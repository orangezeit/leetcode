class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n(profit.size());
        vector<vector<int>> v(n, vector<int>(3));
        for (int i = 0; i < n; ++i) {
            v[i][0] = endTime[i];
            v[i][1] = startTime[i];
            v[i][2] = profit[i];
        }

        sort(v.begin(), v.end());
        vector<vector<int>> dp = {{0, 0}}; //init state: endTime(0), profit(0)

        for (const vector<int>& task: v) {
            //int i = 0;

            auto it = --lower_bound(dp.begin(), dp.end(), task, [](const vector<int>& a, const vector<int>& b) {return a[0] <= b[1];});
            int curr = (*it)[1] + task[2];
            if (curr > dp.back()[1])
                dp.push_back({task[0], curr});
        }
        return dp.back()[1];
    }
};
