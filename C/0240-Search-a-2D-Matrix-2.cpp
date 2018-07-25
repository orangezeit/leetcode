    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Method 1: Brute Force (omitted)
        // Method 2
        if (matrix.empty()) {
            return false;
        }
        
        int r = 0;
        int c = matrix[0].size() - 1;
        
        while (r < matrix.size() && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else {
                matrix[r][c] < target ? r++ : c--;
            }
        }
        
        return false;
    }
