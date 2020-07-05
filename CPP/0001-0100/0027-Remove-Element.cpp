class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        int c(nums.size());
        for (int i = 0, k = 0; i < nums.size(); ++i)
            nums[i] == val ? c-- : nums[k++] = nums[i];
        return c;
    }
};
