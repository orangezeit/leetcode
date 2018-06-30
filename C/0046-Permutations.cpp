    void permuteHelper(vector<int> nums, vector<int> permute, vector<vector<int>>& permutes) {
        if (nums.empty()) {
            permutes.push_back(permute);
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                int k = nums[i];
                permute.push_back(k);
                nums.erase(nums.begin()+i);
                
                permuteHelper(nums, permute, permutes);
                
                permute.pop_back();
                nums.insert(nums.begin()+i, k);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permute;
        vector<vector<int>> permutes;
        
        permuteHelper(nums, permute, permutes);
        
        return permutes;
    }
