    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        bool h(false), v(false);
        
        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[0].size(); ++j) {
                
                if (i) {
                    if (j) {
                        if (obstacleGrid[i][j]) {
                            obstacleGrid[i][j] = 0;
                        } else {
                            obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                        }
                    } else {
                        if (obstacleGrid[i][j]) {
                            obstacleGrid[i][j] = 0;
                            v = true;
                        } else if (!v) {
                            obstacleGrid[i][j] = 1;
                        }
                    }
                } else {
                    if (obstacleGrid[i][j]) {
                        obstacleGrid[i][j] = 0;
                        h = true;
                        if (j == 0) {
                            v = true;
                        }
                    } else if (!h) {
                        obstacleGrid[i][j] = 1;
                    }
                }
                
            }
        }
        
        return obstacleGrid.back().back();
    }
