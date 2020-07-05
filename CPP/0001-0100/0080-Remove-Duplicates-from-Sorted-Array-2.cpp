class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        int i = 0;
        for (int j = 0; j < nums.size(); ++j)
            if (i < 2 || nums[j] > nums[i - 2])
                nums[i++] = nums[j];
        return i;
    }
};
