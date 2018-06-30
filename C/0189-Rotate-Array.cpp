    void rotate(vector<int>& nums, int k) {
        // Method 1
        for (int i = 0; i < k % nums.size(); ++i) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
        
        // Method 2
        vector<int> vec(nums.end() - k % nums.size(), nums.end());
        vec.insert(vec.end(), nums.begin(), nums.end());
        vec.resize(nums.size());
        nums = vec;
    }
