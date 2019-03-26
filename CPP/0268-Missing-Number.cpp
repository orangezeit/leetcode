    int missingNumber(vector<int>& nums) {
        int n(nums.size()), sum(0);
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
        }
        return n*(n+1)/2 - sum;
    }
