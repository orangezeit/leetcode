vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        vector<vector<int>> path(R * C, vector<int>(2));
        int step = 0;
        int dir = 0;
        bool flag = true;
        int i = 0;
        
        while (i < R * C) {
            if (flag) step++;
            for (int k = 0; k < step; ++k) {
                if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) path[i++] = {r0, c0};
                r0 += d[dir % 4][0];
                c0 += d[dir % 4][1];
            }
            flag = !flag;
            dir++;
        }
        
        return path;
    }
