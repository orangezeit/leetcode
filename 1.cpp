class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j, k, c(nums.size());
        vector<int> nums_copy(nums.size()), record(2);

        nums_copy = nums;
        
        sort(nums.begin(), nums.end());
        
        for (i = 0; i < nums.size(); ++i) {
            if (target <= nums[i] - nums[0]) {
                c = i;
            }
        }
        
        for (i = 0; i < c; ++i) {
            for (j = i + 1; j < c; ++j) {
                if (nums[i] + nums[j] == target) {
                    if (nums[i] != nums[j]) {
                       for (k = 0; k < nums.size(); ++k) {
                            if (nums[i] == nums_copy[k]) {record[0] = k;}
                            else if (nums[j] == nums_copy[k]) {record[1] = k;}
                        }
                        return record; 
                    } else {
                        for (k = 0; k < nums.size(); ++k) {
                            if (nums[i] == nums_copy[k]) {record[0] = k;nums[i]++;}
                            else if (nums[j] == nums_copy[k]) {record[1] = k;}
                        }
                        return record;
                    }
                }
            }
        }
    }
};
