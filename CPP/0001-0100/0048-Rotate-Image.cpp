class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Time Complexity: O(N^2)
        // Space Complexity: O(1)
        int n(matrix.size());
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - i - 1; ++j) {
                swap(matrix[i][j], matrix[j][n - i - 1]);
                swap(matrix[n - i - 1][n - j - 1], matrix[n - j - 1][i]);
                swap(matrix[i][j], matrix[n - i - 1][n - j - 1]);
            }
        }
    }
};
