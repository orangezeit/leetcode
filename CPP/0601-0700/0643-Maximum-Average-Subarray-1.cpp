class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0), mx(sum);
        for (int i = k; i < nums.size(); ++i)
            mx = max(mx, sum += nums[i] - nums[i-k]);
        return (double) mx / k;
    }
};
