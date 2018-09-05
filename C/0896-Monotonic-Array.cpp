    bool isMonotonic(vector<int>& A) {
        bool increase(false), decrease(false);
        
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i] < A[i+1]) {
                if (decrease) return false;
                increase = true;
            } else if (A[i] > A[i+1]) {
                if (increase) return false;
                decrease = true;
            }
        }
        
        return true;
    }
