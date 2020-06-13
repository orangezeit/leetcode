    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Method 1: Brute Force (omitted)
        
        // Method 2: Hash map
        // Time Complexity: O(n)
        // Space Complexity: O(n)
        
        unordered_map<int,int> record;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) == record.end()) {
                record.insert({nums[i], i});
            } else {
                if (i - record[nums[i]] <= k) {
                    return true;
                } else {
                    record[nums[i]] = i;
                }
            }
        }
        
        return false;
        
        // Method 3: Hash table
        // Time Complexity: O(n)
        // Space Complexity: O(k)
        
        unordered_set<int> record;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (record.find(nums[i]) != record.end()) {
                return true;
            }
            
            record.insert(nums[i]);
            
            if (record.size() == k + 1) {
                record.erase(nums[i-k]);
            }
        }
        
        return false;
    }
