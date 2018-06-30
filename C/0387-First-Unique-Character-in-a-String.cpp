    int firstUniqChar(string s) {
        vector<int> letters(26, -1);
        
        for (int i = 0; i < s.length(); ++i) {
            if (letters[s[i]-'a'] == -1) {
                letters[s[i]-'a'] = i;
            } else {
                letters[s[i]-'a'] = -2;
            }
        }
        
        for (int i = 0; i < s.length(); ++i) {
            if (letters[s[i]-'a'] >= 0) {
                return i;
            }
        }
        
        return -1;
    }
