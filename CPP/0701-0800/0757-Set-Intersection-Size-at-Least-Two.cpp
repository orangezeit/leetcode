class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // sort intervals by the end point
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1] || a[1] == b[1] && a[0] > b[0];
        });
        int ans(0), left(-1), right(-1);
        for (auto& inv: intervals) {
            if (inv[0] <= left) continue;
            else if (inv[0] > right) {
                ans += 2;
                left = inv[1] - 1;
                right = inv[1];
            } else {
                ans++;
                left = right;
                right = inv[1];
            }
        }
        return ans;
    }
};
