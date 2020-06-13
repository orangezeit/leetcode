    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> hashset;
        vector<int> res(2);
        int n(nums.size()), sum(0);
        
        
        for (int i = 0; i < n; ++i) {
            if (hashset.find(nums[i]) == hashset.end()) {
                hashset.insert(nums[i]);
                sum += nums[i];
            } else {
                res[0] = nums[i];
            }
        }
        
        res[1] = n * (n + 1) / 2 - sum;
        
        return res;
    }
