class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int, int>> dp(A.size());
        int res(1);

        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = A[i] - A[j];

                dp[i][diff] = max(dp[j][diff], 1) + 1;
                res = max(res, dp[i][diff]);
            }
        }

        return res;
    }
};
