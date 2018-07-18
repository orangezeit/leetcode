    bool isAnagram(string s, string t) {
        // Method 1
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        
        // Method 2
        if (s.length() != t.length()) {
            return false;
        } else {
            vector<int> letters(26, 0);
            
            for (int i = 0; i < s.length(); ++i) {
                letters[s[i]-'a']++;
                letters[t[i]-'a']--;
            }
            
            return letters == vector<int>(26, 0);
        }
    }
