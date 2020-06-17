class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> ans(A.size());

        for (int i = 0; i < A.size(); ++i) {
            int temp = A[i];
            for (int j = 0; j < K; ++j) {
                if (i + j == A.size()) break;
                temp = max(temp, A[i + j]);
                ans[i + j] = max(ans[i + j], (j + 1) * temp + (i ? ans[i-1] : 0));
            }
        }

        return ans.back();
    }
};
