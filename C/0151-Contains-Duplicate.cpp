    bool containsDuplicate(vector<int>& nums) {
        // Method 1
        sort(nums.begin(), nums.end());
        return distance(nums.begin(), unique(nums.begin(), nums.end())) != nums.size();
        
        // Method 2
        unordered_set<int> record;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) == record.end()) {
                record.insert(nums[i]);
            } else {
                return true;
            }
        }
        
        return false;
    }
