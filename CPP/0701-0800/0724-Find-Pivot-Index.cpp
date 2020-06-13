    int pivotIndex(vector<int>& nums) {
        nums.push_back(0);
        int left = 0;
        int right = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            right += nums[i];
        }
        
        for (int i = 0; i < nums.size()-1; ++i) {
            if (left == right) return i;
            left += nums[i];
            right -= nums[i+1];
        }
        
        return -1;
    }
