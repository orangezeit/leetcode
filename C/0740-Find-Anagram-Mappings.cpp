    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> record;
        
        for (int i = 0; i < B.size(); ++i) {
            record[B[i]] = i;
        }
        
        for (int i = 0; i < A.size(); ++i) {
            A[i] = record[A[i]];
        }
        
        return A;
    }
