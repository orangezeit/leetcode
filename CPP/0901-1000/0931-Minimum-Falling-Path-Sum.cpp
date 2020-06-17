class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int sum(A[0][0]), n(A.size());

        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i+1][j] += min(A[i][j], min(j ? A[i][j-1] : INT_MAX, j < n - 1 ? A[i][j+1] : INT_MAX));
            }
        }

        return *min_element(A.back().begin(), A.back().end());
    }
};
