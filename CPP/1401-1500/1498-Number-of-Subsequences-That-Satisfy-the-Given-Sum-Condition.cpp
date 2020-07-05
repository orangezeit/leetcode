class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pows(n);
        pows[0] = 1;
        for (int i = 1; i < n; ++i)
            pows[i] = 2 * pows[i - 1] % 1000000007;
        sort(nums.begin(), nums.end());
        long ans(0);
        int i(0), j(n - 1);
        while (i <= j) {
            while (i <= j && nums[i] + nums[j] > target) j--;
            if (i > j) break;
            ans = (ans + pows[j - i]) % 1000000007;
            i++;
        }
        return ans;
    }
};
