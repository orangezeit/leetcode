    int singleNumber(vector<int>& nums) {
        unordered_set<int> record, repeated;
        
        for(int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) == record.end() && repeated.find(nums[i]) == repeated.end()) {
                record.insert(nums[i]);
            } else {
                record.erase(nums[i]);
                repeated.insert(nums[i]);
            }
        }
        
        return *record.begin();
    }
