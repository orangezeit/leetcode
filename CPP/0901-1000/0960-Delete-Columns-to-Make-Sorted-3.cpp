class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int k, m(A.size()), n(A[0].size()), res(n - 1), dp[n]({});

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                for (k = 0; k < m; ++k) {
                    if (A[k][i] > A[k][j])
                        break;
                }
                if (k == m && dp[i] + 1 > dp[j])
                    dp[j] = dp[i] + 1;
                res = min(res, n - dp[j] - 1);
            }
        }

        return res;
    }
};
