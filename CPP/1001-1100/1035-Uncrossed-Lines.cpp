class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        // largest common subsequence

        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));

        for (int i = 1; i < A.size() + 1; ++i)
            for (int j = 1; j < B.size() + 1; ++j)
                dp[i][j] = A[i - 1] == B[j - 1] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);

        return dp.back().back();
    }
};
