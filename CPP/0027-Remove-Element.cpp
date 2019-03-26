    int removeElement(vector<int>& nums, int val) {
        int k(0), c(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] == val ? c-- : nums[k++] = nums[i];
        }
        
        return c;
    }
