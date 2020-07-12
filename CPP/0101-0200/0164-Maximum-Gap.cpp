#include<cmath>
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int mn(INT_MAX), mx(INT_MIN), n(nums.size());
        for (int i: nums) {
            mn = min(mn, i);
            mx = max(mx, i);
        }

        int gap = ceil((double)(mx - mn) / (n - 1));
        if (!gap) return 0;
        //cout << gap << endl;
        vector<int> ub(n, INT_MIN), lb(n, INT_MAX);
        for (int i: nums) {
            int idx = (i - mn) / gap;
            //cout << idx << endl;
            ub[idx] = max(ub[idx], i);
            lb[idx] = min(lb[idx], i);
        }
        //cout << gap << endl;
        int prev(mn);
        for (int i = 0; i < n; ++i) {
            if (lb[i] == INT_MAX && ub[i] == INT_MIN) continue;
            gap = max(gap, lb[i] - prev);
            prev = ub[i];
        }
        return max(gap, mx - prev);
    }
};
