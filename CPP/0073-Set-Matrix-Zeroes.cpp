    void setZeroes(vector<vector<int>>& matrix) {
        // Space Complexity: O(c)
        bool fr(false), fc(false);
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    fr |= i == 0;
                    fc |= j == 0;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            } else if (fr) {
                matrix[0][j] = 0;
            }
        }
        
        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            } else if (fc) {
                matrix[i][0] = 0;
            }
        }
    }
