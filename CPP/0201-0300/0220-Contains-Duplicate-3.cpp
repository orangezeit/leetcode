    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> record;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            if (record.lower_bound((long long)nums[i] - t) != record.end() && *record.lower_bound((long long)nums[i] - t) - t <= nums[i]) {
                return true;
            }
            
            // for nums[i], if we can find a number that is not less than
            // nums[i] - t and not greater than nums[i] + t, we conclude
            // there exists a nearby-almost duplicate and return true.
            
            record.insert(nums[i]);
            
            if (record.size() == k + 1) {
                record.erase(nums[i-k]);
            }
        }
        
        return false;
    }
