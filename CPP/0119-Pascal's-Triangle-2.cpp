    vector<int> getRow(int rowIndex) {
        vector<int> row(1,1);
        
        while (rowIndex--) {
            for (int i = row.size() - 1; i >= 1; --i) {
                row[i] += row[i-1];
            }
            row.push_back(1);
        }
        
        return row;
    }
