class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        vector<int> newNums(nums.size());

        for (int i = nums.size()/2; i < nums.size(); i++) {
            newNums[2*(i - nums.size()/2)] = nums[i];
        }
        for (int i = 0; i < nums.size()/2; i++) {
            newNums[2*i+1] = nums[i];
        }
        nums = newNums;
    }
};
