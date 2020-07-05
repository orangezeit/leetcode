class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m(mat.size()), n(mat[0].size());
        vector<vector<int>> rec(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                rec[i][j] = mat[i-1][j-1] + rec[i][j-1] + rec[i-1][j] - rec[i-1][j-1];
            }
        }

        for (int len = min(m, n); len >= 1; --len) {
            for (int i = 0; i <= m - len; ++i) {
                for (int j = 0; j <= n - len; ++j) {
                    int temp =  rec[i+len][j+len] - rec[i+len][j] - rec[i][j + len] + rec[i][j];
                    if (temp <= threshold) return len;
                }
            }
        }

        return 0;
    }
};
