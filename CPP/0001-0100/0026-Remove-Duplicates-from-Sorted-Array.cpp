class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        nums.emplace_back(INT_MAX);
        int k(0);
        for (int i = 0; i + 1 < nums.size(); ++i) {
            if (nums[i] == nums[i + 1]) continue;
            nums[k++] = nums[i];
        }
        return k;
    }
};

