    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() <= 2) {
            return 0;
        }
        
        vector<int> diffs(A.size());
        
        for (int i = 0; i < A.size()-1; ++i) {
            diffs[i] = A[i+1] - A[i];
        }
        
        diffs.back() = INT_MAX;
        int sum = 0;
        int k = -1;
        
        for (int i = 0; i < diffs.size()-1; ++i) {
            if (diffs[i] != diffs[i+1]) {
                sum += (i-k) * (i-k-1) / 2;
                k = i;
            }
        }
        
        return sum;
    }
