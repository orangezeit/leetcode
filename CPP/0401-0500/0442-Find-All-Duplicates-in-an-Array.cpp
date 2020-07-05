class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (const int& i: nums) {
            int idx = abs(i) - 1;
            if (nums[idx] < 0)
                ans.emplace_back(abs(i));
            nums[idx] *= -1;
        }
        return ans;
    }
};
