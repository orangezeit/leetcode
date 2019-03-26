    vector<string> summaryRanges(vector<int>& nums) {
        nums.push_back(INT_MAX);
        vector<string> ranges;
        int k = 0;
        
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] + 1 != nums[i+1]) {
                i == k ? ranges.push_back(to_string(nums[i])) : ranges.push_back(to_string(nums[k]) + "->" + to_string(nums[i]));
                k = i+1;
            }
        }
        
        return ranges;
    }
