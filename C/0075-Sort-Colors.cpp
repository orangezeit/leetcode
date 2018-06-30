    void sortColors(vector<int>& nums) {
        // Method 1: counting sort
        
        int r(0), w(0), b(0);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                r++;
            } else if (nums[i] == 1) {
                w++;
            } else {
                b++;
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i < r) {
                nums[i] = 0;
            } else if (i < r+w) {
                nums[i] = 1;
            } else {
                nums[i] =2;
            }
        }
        
        
        // Method 2: Quicksort 3-way
        
        int zero = -1;
        int two = nums.size();
        int i = 0;
        
        while (i < two) {
            if (nums[i] == 1) {
                i++;
            } else if (nums[i] == 2) {
                swap(nums[--two], nums[i]);
            } else {
                swap(nums[++zero], nums[i++]);
            }
        }
    }
