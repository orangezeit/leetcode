    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        vector<int> nums2 = nums;
        int maxPro = nums[0];
        int minPro = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                nums[i] = max(nums[i], nums[i-1] * nums[i]);
                nums2[i] = min(nums2[i], nums2[i-1] * nums2[i]);
            } else {
                nums[i] = max(nums[i], nums2[i-1] * nums[i]);
                nums2[i] = min(nums2[i], nums[i-1] * nums2[i]);
            }
            
            maxPro = max(maxPro, nums[i]);
        }
        
        return maxPro;
    }
