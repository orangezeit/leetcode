vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int, int> record;

    for (int i = 0; i < nums.size(); ++i) {
        if (record.find(target - nums[i]) == record.end()) {
            record[nums[i]] = i;
        } else {
            return {record[target - nums[i]], i};
        }
    }
}
