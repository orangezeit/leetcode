    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        } else {
            vector<int> sletters(26, 0), tletters(26, 0);
            
            for (int i = 0; i < s.length(); ++i) {
                sletters[s.at(i)-'a']++;
                tletters[t.at(i)-'a']++;
            }
            
            return sletters == tletters;
        }
    }
