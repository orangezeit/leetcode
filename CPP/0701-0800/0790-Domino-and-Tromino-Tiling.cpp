class Solution {
public:
    int numTilings(int n) {
        if (n < 3) return n;

        vector<long> nums(n+1);
        nums[0] = nums[1] = 1;
        nums[2] = 2;

        for (int i = 3; i <= n; ++i)
            nums[i] = (2 * nums[i - 1] + nums[i - 3]) % 1000000007;

        return nums[n];
    }
};
