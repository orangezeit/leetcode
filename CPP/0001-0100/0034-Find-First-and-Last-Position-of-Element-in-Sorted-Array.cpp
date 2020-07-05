class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // Time Complexity: O(lg N)
        // Space Complexity: O(1)
        int left = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
        if (left == nums.size() || nums[left] != target) return {-1, -1};
        int right = distance(nums.begin(), --upper_bound(nums.begin(), nums.end(), target));
        return {left, right};
    }
};
