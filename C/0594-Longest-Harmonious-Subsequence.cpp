    int findLHS(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int l(0);
        unordered_map<int, int> counts;
        
        for(int i = 0; i < nums.size(); ++i) {
            counts[nums[i]]++;
        }
        
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            if (counts.find(it->first + 1) != counts.end()) {
                l = max(l, it->second + counts.find(it->first + 1)->second);
            }
        }
        
        return l;
    }
