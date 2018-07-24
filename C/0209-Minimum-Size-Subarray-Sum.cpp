    int minSubArrayLen(int s, vector<int>& nums) {
        int i(0), j(0), sum(0), l(INT_MAX);
        
        while (i < nums.size()) {
            sum += nums[i++];
            
            while (sum >= s) {
                l = min(l, i - j);
                sum -= nums[j++];
            }
        }
        
        return l == INT_MAX ? 0 : l;
    }
