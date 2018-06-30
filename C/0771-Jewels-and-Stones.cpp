    int numJewelsInStones(string J, string S) {
        unordered_set<char> record(J.begin(), J.end());
        int num(0);
        
        for (int i = 0; i < S.length(); ++i) {
            if (record.find(S[i]) != record.end()) {
                num++;
            }
        }
        
        return num;
    }
