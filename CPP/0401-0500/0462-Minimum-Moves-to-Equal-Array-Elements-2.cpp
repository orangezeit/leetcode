class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n(nums.size()), target((nums[n / 2] + nums[(n - 1) / 2]) / 2), ans(0);
        for (int i = 0; i < n; ++i)
            ans += (nums[i] - target) * (i >= n / 2 + n % 2 ? 1 : -1);
        return ans;
    }
};
