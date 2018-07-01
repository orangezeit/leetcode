    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> record;
        
        for(int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) == record.end()) {
                record.insert(nums[i]);
            } else {
                record.erase(nums[i]);
            }
        }
        
        return vector<int>(record.begin(), record.end());
    }
