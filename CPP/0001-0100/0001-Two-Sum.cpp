class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Time Complexity: O(N)
        // Space Complexity: O(N)
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i)
            if (record.count(target - nums[i]))
                return {record[target - nums[i]], i};
            else
                record[nums[i]] = i;
        return {};
    }
};
