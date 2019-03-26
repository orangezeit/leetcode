    bool canJump(vector<int>& nums) {
        int x = nums.size()-1;
        
        while (x) {
            for (int i = x-1; i >= 0; --i) {
                if (nums[i] + i >= x) {
                    x = i;
                    break;
                }
                
                if (i == 0) {
                    return false;
                }
            }
        }
        
        return x == 0;
    }
