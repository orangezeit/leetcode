    vector<vector<int>> generateMatrix(int n) {
        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        
        int dir = 0;
        int i = 0;
        int r = 0;
        int c = 0;
        
        while (i < n * n) {
            if (r >= 0 && r < n && c >= 0 && c < n) {
                if (matrix[r][c] == 0) {
                    matrix[r][c] = ++i;
                    r += d[dir % 4][0];
                    c += d[dir % 4][1];
                    continue;
                }
                
            }
            
            r -= d[dir % 4][0];
            c -= d[dir % 4][1];
            dir++;
            r += d[dir % 4][0];
            c += d[dir % 4][1];
        }
        
        return matrix;
    }
