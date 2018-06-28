    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        } else {
            vector<int> s_letters(26, 0), t_letters(26, 0);
            
            for (int i = 0; i < s.length(); ++i) {
                s_letters[s[i]-'a']++;
                t_letters[t[i]-'a']++;
            }
            
            return s_letters == t_letters;
        }
    }
