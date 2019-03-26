    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int c(-1), l(0);
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]-1) {
                l = max(l, i-c-1);
                c = i;
            }
        }
        
        return l;
    }
