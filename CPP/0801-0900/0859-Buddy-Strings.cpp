    bool buddyStrings(string A, string B) {
        if (A.length() != B.length()) {
            return false;
        }
        
        if (A.length() < 2) {
            return false;
        }
        unordered_set<char> letters;
        bool repeated = false;
        int p[2];
        int k = 0;
            
        for (int i = 0; i < A.length(); ++i) {
            if (A[i] != B[i]) {
                if (k == 2) {
                    return false;
                }
                p[k++] = i;
            }
                
            if (letters.find(A[i]) == letters.end()) {
                letters.insert(A[i]);
            } else {
                repeated = true;
            }
        }
            
        if (k == 0) {
            return repeated;
        } else if (k == 1) {
            return false;
        } else {
            return A[p[0]] == B[p[1]] && A[p[1]] == B[p[0]];
        }
    }
