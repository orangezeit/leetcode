class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int n(nums.size());
        int ans(0), mn(100001), mx(-100001), res(0);
        for (int i = 0; i < n-1; ++i) {
            int d = abs(nums[i+1] - nums[i]);
            ans += d;
            res = max(res, abs(nums[n-1] - nums[i]) - d);
            res = max(res, abs(nums[i+1] - nums[0]) - d);
            mn = min(mn, max(nums[i], nums[i + 1]));
            mx = max(mx, min(nums[i], nums[i + 1]));
        }

        return ans + max(res, 2 * (mx - mn));
    }
};
