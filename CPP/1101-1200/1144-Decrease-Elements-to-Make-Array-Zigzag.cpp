class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        // odd greater
        int ans1(0), ans2(0);

        for (int i = 0; i < nums.size(); i += 2) {
            // odd smaller
            int temp(INT_MAX);
            if (i - 1 >= 0 && nums[i - 1] <= nums[i])
                temp = min(temp, nums[i - 1]);
            if (i + 1 < nums.size() && nums[i + 1] <= nums[i])
                temp = min(temp, nums[i + 1]);
                //ans1 += (nums[i + 1] - nums[i] + 1);
            ans1 += temp != INT_MAX ? (nums[i] - temp) + 1 : 0;
            temp = INT_MAX;

            // even smaller
            if (i + 1 < nums.size() && nums[i] <= nums[i + 1])
                temp = min(temp, nums[i]);
                //ans2 += (nums[i] - nums[i + 1] + 1);
            if (i + 2 < nums.size() && nums[i + 2] <= nums[i + 1])
                temp = min(temp, nums[i + 2]);
            if (i + 1 < nums.size())
                ans2 += temp != INT_MAX ? (nums[i + 1] - temp) + 1 : 0;
                //ans2 += (nums[i + 2] - nums[i + 1] + 1);
        }
        //cout << ans1 << " " << ans2 << endl;
        return min(ans1, ans2);
    }
};
