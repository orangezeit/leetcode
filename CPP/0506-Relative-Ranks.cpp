    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> nums_copy = nums;
        sort(nums_copy.rbegin(), nums_copy.rend());
        unordered_map<int, string> ranks;
        vector<string> res(nums.size());
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) ranks[nums_copy[i]] = "Gold Medal";
            else if (i == 1) ranks[nums_copy[i]] = "Silver Medal";
            else if (i == 2) ranks[nums_copy[i]] = "Bronze Medal";
            else ranks[nums_copy[i]] = to_string(i+1);
        }
        
        for (int i = 0; i < nums.size(); ++i) res[i] = ranks.find(nums[i])->second;
        return res;
    }
