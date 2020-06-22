class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (!k) {
            for (int i = 1; i < nums.size(); ++i)
                if (!(nums[i] || nums[i-1]))
                    return true;
            return false;
        }
        unordered_set<int> rec;
        nums[0] %= k;
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];
            nums[i] %= k;
            if (!nums[i]) return true;
            if (i >= 2) {
                rec.insert(nums[i-2]);
                if (rec.find(nums[i]) != rec.end()) return true;
            }
        }
        return false;
    }
};
