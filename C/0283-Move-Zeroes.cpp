    void moveZeroes(vector<int>& nums) {
        int c(0), n(nums.size());
        
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                if (i != c) {
                    swap(nums[c++], nums[i]);
                } else {
                    c++;
                }
            }
        }
    }
