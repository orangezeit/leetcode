class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        if (nums[nums.size() / 2] != target)
            return false;
        return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target) > nums.size() / 2;
    }
};
