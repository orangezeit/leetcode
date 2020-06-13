    int firstMissingPositive(vector<int>& nums) {
        // Method 1
        
        nums.push_back(0);
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i+1] - nums[i] > 1 && nums[i] + 1 > 0) {
                return nums[i] + 1;
            }
        }
        
        return nums.back()+1;
        
        // Method 2
        vector<pair<int, int>> intervals;
        intervals.push_back({1, INT_MAX});
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                for (int j = 0; j < intervals.size(); ++j) {
                    if (nums[i] >= intervals[j].first && nums[i] <= intervals[j].second) {
                        if (intervals[j].first == intervals[j].second) {
                            intervals.erase(intervals.begin()+j);
                        } else if (nums[i] == intervals[j].first) {
                            intervals[j].first++;
                        } else if (nums[i] == intervals[j].second) {
                            intervals[j].second--;
                        } else {
                            intervals.insert(intervals.begin()+j, {intervals[j].first, nums[i]-1});
                            intervals[j+1].first = nums[i]+1;
                        }
                
                        break;
                    }
                }
            }
        }
        
        return intervals[0].first;
    }
