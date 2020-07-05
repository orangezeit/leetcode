class Solution {
public:
    int minDifficulty(vector<int>& jd, int d) {
        // Time Complexity: O(D * N^2)
        // Space Complexity: O(N)
        int n(jd.size());
        if (d > n) return -1;
        vector<int> dp(n);
        dp[0] = jd[0];
        for (int i = 1; i < n; ++i)
            dp[i] = max(dp[i-1], jd[i]);

        for (int i = 1; i < d; ++i) {
            vector<int> temp(n, 300000);
            for (int j = 0; j < n; ++j) {
                int mx = jd[j];
                for (int k = j; k > 0; --k) {
                    mx = max(mx, jd[k]);
                    temp[j] = min(temp[j], dp[k - 1] + mx);
                }
            }
            swap(dp, temp);
        }

        return dp.back();
    }
};
