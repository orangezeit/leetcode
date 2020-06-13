    string shiftingLetters(string S, vector<int>& shifts) {
        if (shifts.empty()) {
            return S;
        }
        
        if (shifts.size() > 1) {
            shifts.back() = shifts.back() % 26;
            for (int i = shifts.size()-1; i >= 1; --i) {
                shifts[i-1] = (shifts[i-1] + (shifts[i] % 26)) % 26;
            }
        }
        
        for (int i = 0; i < S.length(); ++i) {
            S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
        }
        
        return S;
    }
