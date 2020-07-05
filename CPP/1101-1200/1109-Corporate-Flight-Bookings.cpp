class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (const vector<int>& b: bookings) {
            ans[b[0] - 1] += b[2];
            if (b[1] != n) ans[b[1]] -= b[2];
        }

        for (int i = 1; i < n; ++i)
            ans[i] += ans[i-1];

        return ans;
    }
};
