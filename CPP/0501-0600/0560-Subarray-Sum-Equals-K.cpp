class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        int ans(0);

        for (int i = 0; i < nums.size(); ++i) {
            if (i) nums[i] += nums[i-1];
            if (nums[i] == k) ans++;
            if (record[nums[i] - k])
                ans += record[nums[i] - k];
            record[nums[i]]++;
        }

        return ans;
    }
};
