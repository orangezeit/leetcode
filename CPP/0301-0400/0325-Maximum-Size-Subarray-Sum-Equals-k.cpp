class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;

        // O(n) use Hashmap
        int s;
        nums[0] == k ? s = 1 : s = 0;
        unordered_map<int, int> record;
        record[nums[0]] = 0;

        for (int i = 1; i < nums.size(); ++i) {
            nums[i] += nums[i-1];

            if (record.find(nums[i]) == record.end())
                record[nums[i]] = i;

            if (nums[i] == k)
                s = i + 1;
            else if (record.find(nums[i] - k) != record.end())
                s = max(s, i - record[nums[i] - k]);
        }


        return s;
    }
};
