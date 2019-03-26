    int matrixScore(vector<vector<int>>& A) {
    
        // Time Complexity: O(n^2)
        // Space Complexity: O(1)
        int x(A.size()), y(A[0].size());
        int score(x * pow(2, y-1));
        
        for (int i = 0; i < x; ++i) {
            if (A[i][0] == 0) {
                for (int j = 0; j < y; ++j) {
                    if (A[i][j]) {
                        A[i][j] = 0;
                    } else {
                        A[i][j] = 1;
                    }
                }
            }
        }
        
        for (int i = 1; i < y; ++i) {
            int c = 0;
            for (int j = 0; j < x; ++j) {
                c += A[j][i];
            }
            score += max(c, x-c) * pow(2, y-i-1);
        }
            
        return score;
    }
