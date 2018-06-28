    string reverseWords(string s) {
        int c(0);
        s += " ";
        
        for(int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                for (int j = c; j < c + (i-c)/2; ++j) {
                    swap(s[j], s[c+i-j-1]);
                }
                c = i + 1;
            }
        }
        
        s.pop_back();
        return s;
    }
