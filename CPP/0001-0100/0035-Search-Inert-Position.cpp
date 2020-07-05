class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Time Complexity: O(lg N)
        // Space Complexity: O(1)
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }
};
