    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> record, repeated;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) == record.end()) {
                record.insert(nums[i]);
            } else {
                repeated.insert(nums[i]);
            }
        }
        
        return vector<int>(repeated.begin(), repeated.end());
    }
