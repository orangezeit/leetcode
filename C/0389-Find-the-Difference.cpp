    char findTheDifference(string s, string t) {
        unordered_map<char, int> record;
        
        for (int i = 0; i < s.length(); ++i) {
            record[s[i]]++;
        }
        
        for (int i = 0; i < t.length(); ++i) {
            record[t[i]]--;
            if (record[t[i]] < 0) {
                return t[i];
            }
        }
    }
