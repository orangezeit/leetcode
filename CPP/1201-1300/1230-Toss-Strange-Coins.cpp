class Solution {
public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        double dp[prob.size() + 1][target + 1] = {1};
        //dp[0][0] = 1;
        for (int i = 1; i <= prob.size(); ++i)
            for (int j = 0; j <= target; ++j)
                dp[i][j] = (j ? dp[i-1][j-1] * prob[i-1] : 0) + dp[i-1][j] * (1 - prob[i-1]);

        return dp[prob.size()][target];
    }
};
