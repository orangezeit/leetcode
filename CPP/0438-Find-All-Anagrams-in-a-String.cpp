    vector<int> findAnagrams(string s, string p) {
        vector<int> idx;
        
        if (s.length() < p.length() || p.length() == 0) {
            return idx;
        }
        
        vector<int> s_letters(26, 0), p_letters(26, 0);
        
        for(int i = 0; i < p.length(); ++i) {
            s_letters[s[i]-'a']++;
            p_letters[p[i]-'a']++;
        }
        
        int j(0), k(p.length());
        
        while (k <= s.length()) {
            if (s_letters == p_letters) {
                idx.push_back(j);
            }
            
            if (k == s.length()) {
                return idx;
            }
            
            s_letters[s[j++]-'a']--;
            s_letters[s[k++]-'a']++;
        }

    }
