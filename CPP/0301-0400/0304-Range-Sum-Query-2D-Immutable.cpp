class NumMatrix {
private:
    vector<vector<int>> x;
public:
    NumMatrix(vector<vector<int>> mat) {
        int m(mat.size());
        if (m == 0) return;
        int n(mat[0].size());
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                mat[i][j] += (i ? mat[i - 1][j] : 0) + (j ? mat[i][j - 1] : 0) - (i && j ? mat[i - 1][j - 1] : 0);
        swap(x, mat);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return x[row2][col2] - (row1 ? x[row1 - 1][col2] : 0) - (col1 ? x[row2][col1 - 1] : 0) + (row1 && col1 ? x[row1 - 1][col1 - 1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
