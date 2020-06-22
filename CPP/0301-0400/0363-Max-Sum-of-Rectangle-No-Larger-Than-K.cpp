class Solution {
private:
    int maxSubArray(vector<int> nums, int k) {
        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum <= k) maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }

public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxSum = INT_MIN;

        vector<int> dp(m, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int r = 0; r < m; ++r) {
                    dp[r] += matrix[r][j];
                    //cout << dp[r] << " ";
                }//cout << endl;
                maxSum = max(maxSum, maxSubArray(dp, k));
                //cout << "ms" << maxSum << endl;
            }
            dp = vector<int>(m, 0);
        }

        return maxSum;
    }
};
