class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int s(0), s2(0);

        sort(nums.rbegin(), nums.rend());
        for (const int& i: nums) s += i;
        for (int i = 0; i < nums.size(); ++i) {
            s2 += nums[i];
            if (s2 > s - s2) return vector<int>(nums.begin(), nums.begin() + i + 1);
        }
        return nums;
    }
};
