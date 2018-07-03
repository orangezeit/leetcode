    int maxRotateFunction(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        
        int sum1(0), sum2(0);
        
        for (int i = 0; i < A.size(); ++i) {
            sum1 += A[i];
            sum2 += A[i] * i;
        }
        
        int maxSum(sum2), k(A.size());
        
        for (int i = 0; i < A.size()-1; ++i) {
            sum2 += (sum1 - A.size() * A[--k]);
            maxSum = max(maxSum, sum2);
        }
        
        return maxSum;
    }
