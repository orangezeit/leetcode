    vector<int> constructRectangle(int area) {
        vector<int> rec(2);
        
        for (int i = 1; i * i <= area; ++i) {
            if (area % i == 0) {
                rec = {area / i, i};
            }
        }
        return rec;
    }
