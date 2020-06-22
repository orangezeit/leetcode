class Solution {
public:
    bool partition(const vector<int>& nums, vector<int> subSums, const int& target, int index) {
        if (index < 0) return true;
        for (int i = 0; i < subSums.size(); ++i) {
            if (subSums[i] + nums[index] <= target) {
                subSums[i] += nums[index];
                if (partition(nums, subSums, target, index - 1))
                    return true;
                subSums[i] -= nums[index];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //return true;
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k) return false;
        sort(nums.begin(), nums.end());
        if (nums.back() > s / k) return false;
        vector<int> subSums(k);
        return partition(nums, subSums, s / k, nums.size() - 1);
    }
};
