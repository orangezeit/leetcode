class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n(nums.size()), maxLen(1), ans(0);
        vector<int> dp(n, 1), cnts(n);

        function<int(int, int)> dfs = [&](int i, int len) {
            if (len == 0) return cnts[i] = 1;
            if (cnts[i]) return cnts[i];
            int res(0);
            for (int k = 0; k < i; ++k)
                if (nums[k] < nums[i] && dp[k] == len - 1)
                    res += dfs(k, len - 1);
            return cnts[i] = max(res, 1);
        };


        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (nums[j] < nums[i])
                    maxLen = max(maxLen, dp[i] = max(dp[i], dp[j] + 1));

        for (int i = 0; i < n; ++i)
            if (dp[i] == maxLen)
                ans += dfs(i, maxLen);

        return ans;
    }
};
