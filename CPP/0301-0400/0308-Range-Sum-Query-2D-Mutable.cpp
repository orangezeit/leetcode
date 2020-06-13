class NumMatrix {
private:
    int r, c;
    vector<vector<int>> nums, tree;
public:
    void updateTree(const int& row, const int& col, const int& val) {
        for (int i = row; i <= r; i += i & (-i))
            for (int j = col; j <= c; j += j & (-j))
                tree[i][j] += val;
    }

    int read(const int& row, const int& col) {
        int sum(0);
        for (int i = row; i > 0; i -= i & (-i))
            for (int j = col; j > 0; j -= j & (-j))
                sum += tree[i][j];
        return sum;
    }

    NumMatrix(const vector<vector<int>>& matrix) {
        r = matrix.size();
        if (!r) return;
        c = matrix[0].size();
        nums = vector<vector<int>>(matrix);
        tree = vector<vector<int>>(r + 1, vector<int>(c + 1));
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j)
                updateTree(i, j, matrix[i-1][j-1]);
    }

    void update(int row, int col, int val) {
        val -= nums[row++][col++];
        updateTree(row, col, val);
        nums[--row][--col] += val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        row2++;
        col2++;
        return read(row2, col2) - read(row2, col1) - read(row1, col2) + read(row1, col1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
