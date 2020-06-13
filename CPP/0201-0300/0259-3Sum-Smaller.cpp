class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n(0);
        
        for (int i = 0; i + 2 < nums.size(); ++i)
            for (int j = i + 1; j + 1 < nums.size(); ++j)
                for (int k = j + 1; k < nums.size(); ++k)
                    if (nums[i] + nums[j] + nums[k] < target)
                        n++;
        
        return n;
    }
};
