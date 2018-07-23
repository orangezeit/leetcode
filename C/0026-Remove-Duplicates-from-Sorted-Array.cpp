    int removeDuplicates(vector<int>& nums) {
        nums.push_back(INT_MAX);
        
        int k(0);
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            nums[i] == nums[i+1] ? continue : nums[k++] = nums[i];
        }
        
        return k;
    }
