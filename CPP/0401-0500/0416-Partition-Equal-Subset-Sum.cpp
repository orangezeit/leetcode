class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for (int i = 0; i < nums.size(); ++i)
            sum += nums[i];

        if (sum % 2)
            return false;

        vector<bool> res(sum + 1, false);
        res[0] = true;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = sum - nums[i]; j >= 0; --j)
                if (res[j] && j + nums[i] <= sum)
                    res[j + nums[i]] = true;
            if (res[sum / 2])
                return true;
        }

        return false;
    }
};
