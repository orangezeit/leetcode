class NumMatrix {
private:
    int r, c;
    vector<vector<int>> ns, tree;
public:
    void update_each(const int& row, const int& col, const int& val) {
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

    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        r = matrix.size();
        c = matrix[0].size();
        swap(ns, matrix);
        tree = vector<vector<int>>(r + 1, vector<int>(c + 1));
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j)
                update_each(i, j, ns[i - 1][j - 1]);
    }

    void update(int row, int col, int val) {
        val -= ns[row++][col++];
        update_each(row, col, val);
        ns[--row][--col] += val;
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
