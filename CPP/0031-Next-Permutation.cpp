class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.empty()) return;
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i+1]) {
                for (int j = nums.size() - 1; j >= i; --j) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        return;
                    }
                    
                }
            }
        }
        
        reverse(nums.begin(), nums.end());
        return;
    }
};
