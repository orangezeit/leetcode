    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rows(numRows);
        int k = 0;
        
        while (k < numRows) {
            if (k == 0) {
                rows[k++] = {1};
            } else {
                rows[k] = rows[k-1];
                for (int i = k - 1; i >= 1; --i) {
                    rows[k][i] += rows[k][i-1];
                }
                rows[k++].push_back(1);
            }
        }
        
        return rows;
    }
