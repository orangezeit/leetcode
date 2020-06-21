class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> dp(pairs.size(), 1);
        int ans(1);
        for (int i = 1; i < pairs.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (pairs[j][1] < pairs[i][0])
                    ans = max(ans, dp[i] = max(dp[i], dp[j] + 1));
        return ans;
    }
};
