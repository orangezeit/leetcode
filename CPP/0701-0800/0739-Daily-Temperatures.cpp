class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> waits(n);
        stack<int> ts, ds;

        for (int i = n - 1; i >= 0; i--) {
            int days = 1;

            while (!ts.empty() && temps[i] >= ts.top()) {
                days += ds.top();
                ds.pop();
                ts.pop();
            }
            waits[i] = ts.empty() ? 0 : days;
            ts.push(temps[i]);
            ds.push(days);

        }

        return waits;
    }
};
