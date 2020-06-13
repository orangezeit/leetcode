private:
    vector<vector<int>> permutes;
public:
    void permuteHelper(vector<int> nums, vector<int> permute) {
        if (nums.empty()) {
            permutes.push_back(permute);
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                permute.push_back(nums[i]);
                nums.erase(nums.begin()+i);
                permuteHelper(nums, permute);
                nums.insert(nums.begin()+i, permute.back());
                permute.pop_back();
                
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> permute;
        sort(nums.begin(), nums.end());
        permuteHelper(nums, permute);
        sort(permutes.begin(), permutes.end());
        permutes.resize(distance(permutes.begin(), unique(permutes.begin(), permutes.end())));
        return permutes;
    }
