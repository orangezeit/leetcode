    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; ++i) {
            for (int j = i; j < matrix.size() - i - 1; ++j) {
                swap(matrix[i][j], matrix[j][matrix.size()-1-i]);
                swap(matrix[matrix.size()-1-i][matrix.size()-1-j], matrix[matrix.size()-1-j][i]);
                swap(matrix[i][j], matrix[matrix.size()-1-i][matrix.size()-1-j]);
            }
        }
    }
