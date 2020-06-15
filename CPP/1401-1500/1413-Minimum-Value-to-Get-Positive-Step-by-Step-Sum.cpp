class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans(nums[0]);
        for (int i = 1; i < nums.size(); ++i)
            ans = min(ans, nums[i] += nums[i - 1]);
        return max(-ans, 0) + 1;
    }
};
