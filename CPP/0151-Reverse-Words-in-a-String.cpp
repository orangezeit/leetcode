    void reverseWords(string &s) {
        s += " ";
        vector<string> words;
        int k = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                if (i-k) {
                    words.push_back(s.substr(k, i-k));
                }
                k = i + 1;
            }
        }
        
        s.clear();
        
        for(int i = words.size() - 1; i >= 0; --i) {
            s += words[i] + " ";
        }
        
        s.pop_back();
    }
