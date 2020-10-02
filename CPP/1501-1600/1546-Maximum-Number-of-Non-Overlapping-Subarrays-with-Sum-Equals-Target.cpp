class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> mp({{0, -1}});
        int s(0);
        int n(nums.size());
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            s += nums[i];
            if (mp.count(s - target))
                dp[i] = mp[s - target] == -1 ? 1 : dp[mp[s - target]] + 1;
            if (i) dp[i] = max(dp[i], dp[i - 1]);
            mp[s] = i;
        }
        return dp[n-1];
    }
};
