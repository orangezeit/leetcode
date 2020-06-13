class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> ans;
        if (nums.empty()) {
            lower != upper ? ans.push_back(to_string(lower) + "->" + to_string(upper)) : ans.push_back(to_string(upper));
            return ans;
        }
        
        if ((long)nums[0] - (long)lower >= 1) {
            (long)nums[0] - (long)lower == 1 ? ans.push_back(to_string(lower)) : ans.push_back(to_string(lower) + "->" + to_string(nums[0]-1));
        }
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            if ((long)nums[i+1] - (long)nums[i] < 2) continue;
            (long)nums[i+1] - (long)nums[i] == 2 ? ans.push_back(to_string(nums[i]+1)) : ans.push_back(to_string(nums[i]+1) + "->" + to_string(nums[i+1]-1));
        }
        
        if ((long)upper - (long)nums.back() >= 1) {
            (long)upper - (long)nums.back() == 1 ? ans.push_back(to_string(upper)) : ans.push_back(to_string(nums.back()+1) + "->" + to_string(upper));
        }
        
        return ans;
    }
};
