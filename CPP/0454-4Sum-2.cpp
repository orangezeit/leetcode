    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N(A.size()), c(0);
        unordered_map<int, int> record;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                record[A[i] + B[j]]++;
            }
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (record.find(-C[i]-D[j]) != record.end()) {
                    c += record[-C[i]-D[j]];
                }
            }
        }
        
        return c;
    }
