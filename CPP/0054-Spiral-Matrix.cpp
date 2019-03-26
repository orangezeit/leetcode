    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        unordered_set<int> indices;
        int R = matrix.size();
        int C = matrix[0].size();
        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> spiral(R * C);
        
        int dir = 0;
        int i = 0;
        int r = 0;
        int c = 0;
        
        while (i < R * C) {
            if (r >= 0 && r < R && c >= 0 && c < C && indices.find(r * C + c) == indices.end()) {
                spiral[i++] = matrix[r][c];
                indices.insert(r * C + c);
                r += d[dir % 4][0];
                c += d[dir % 4][1];
            } else {
                r -= d[dir % 4][0];
                c -= d[dir % 4][1];
                dir++;
                r += d[dir % 4][0];
                c += d[dir % 4][1];
            }
        }
        
        return spiral;
    }
