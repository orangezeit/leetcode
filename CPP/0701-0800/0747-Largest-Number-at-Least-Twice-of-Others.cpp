class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        vector<int> nums_copy(nums);
        sort(nums.rbegin(), nums.rend());

        return nums[0] < 2 * nums[1] ? -1 : find(nums_copy.begin(), nums_copy.end(), nums[0]) - nums_copy.begin();
    }
};
