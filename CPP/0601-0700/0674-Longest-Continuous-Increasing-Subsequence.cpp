class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len(1), ans(1);
        nums.emplace_back(INT_MIN);

        for (int i = 0; i + 1 < nums.size(); ++i)
            nums[i] < nums[i + 1] ? ans = max(ans, ++len) : len = 1;

        return ans;
    }
};
