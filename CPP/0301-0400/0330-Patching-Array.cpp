class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long miss(1), i(0), ans(0);
        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i++];
            } else {
                ans++;
                miss <<= 1;
            }
        }

        return ans;
    }
};
