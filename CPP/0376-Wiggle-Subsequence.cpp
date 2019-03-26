    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        vector<vector<int>> updown(nums.size(), vector<int>(2,1));
        // first line: previously increased, second line: previously decreased
        
        int l = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    updown[i][0] = max(updown[i][0], updown[j][1] + 1);
                    l = max(l, updown[i][0]);
                } else if (nums[j] > nums[i]) {
                    updown[i][1] = max(updown[i][1], updown[j][0] + 1);
                    l = max(l, updown[i][1]);
                }
            }
        }
        
        return l;
    }
