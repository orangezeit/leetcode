    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        } else {
            int minTotal = INT_MAX;
            
            for (int i = 1; i < triangle.size(); ++i) {
                for (int j = 0; j < triangle[i].size(); ++j) {
                    if (j == 0) {
                        triangle[i][j] += triangle[i-1][j];
                    } else if (j == triangle[i].size()-1) {
                        triangle[i][j] += triangle[i-1][j-1];
                    } else {
                        triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                    }
                    
                    if (i == triangle.size()-1) {
                        minTotal = min(minTotal, triangle[i][j]);
                    }
                }
            }
            
            return minTotal;
        }
    }
