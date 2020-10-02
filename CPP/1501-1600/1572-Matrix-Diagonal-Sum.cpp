class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // Time Complexity: O(N)
        // Space Complexity: O(1)
        int n(mat.size()), ans(0);
        for (int i = 0; i < n; ++i)
            ans += mat[i][i] + mat[i][n - i - 1];
        if (n % 2) ans -= mat[n / 2][n / 2];
        return ans;
    }
};
