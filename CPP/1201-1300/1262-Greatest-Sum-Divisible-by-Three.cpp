class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        //vect
        int dp[3] = {0, INT_MIN, INT_MIN};
        for (const int& i: nums) {
            int new_dp[3] = {};
            for (int k = 0; k < 3; ++k)
                new_dp[(k + i) % 3] = max(dp[(k + i) % 3], dp[k] + i);
            dp[0] = new_dp[0];
            dp[1] = new_dp[1];
            dp[2] = new_dp[2];
        }
        return dp[0];
    }
};
