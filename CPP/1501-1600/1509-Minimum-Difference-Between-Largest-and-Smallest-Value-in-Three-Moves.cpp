class Solution {
public:
    int minDifference(vector<int>& nums) {
        // Time Complexity: O(N lg N)
        // Space Complexity: O(1)
        if (nums.size() <= 3) return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans(INT_MAX);
        for (int i = 1; i <= 4; ++i)
            ans = min(ans, nums[n - i] - nums[4 - i]);
        return ans;
    }
};
