class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) return false;

        for (int i = 1; i < nums.size(); ++i)
            nums[i] += nums[i-1];

        for (int j = 3; j < nums.size() - 3; ++j) {
            unordered_set<int> equals;

            for (int i = 1; i < j - 1; ++i)
                if (nums[i-1] == nums[j-1] - nums[i])
                    equals.insert(nums[i-1]);

            for (int i = j + 2; i < nums.size() - 1; ++i) {
                int s1(nums[i-1] - nums[j]), s2(nums.back() - nums[i]);
                if (s1 == s2 && equals.count(s1)) return true;
            }
        }

        return false;
    }
};
