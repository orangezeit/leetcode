    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> record;
        int c = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            vector<int> letters(52, 0);
            string str;
            
            for (int j = 0; j < A[i].length(); ++j)
                letters[A[i][j] - 'a' + 26 * (j % 2)]++;
            
            for (int j = 0; j < 52; ++j)
                str += to_string(letters[j]) + " ";
            
            if (record.find(str) == record.end()) {
                c++;
                record.insert(str);
            }
        }
        
        return c;
    }
