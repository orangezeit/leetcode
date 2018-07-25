    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        
        int m(matrix.size()), n(matrix[0].size()), i(0), j(m * n - 1);
        
        while (i <= j) {
            int k = (i + j) / 2;
            
            if (matrix[k / n][k % n] == target) {
                return true;
            } else {
                matrix[k / n][k % n] < target ? i = k + 1 : j = k - 1;
            }
        }
        
        return false;
    }
