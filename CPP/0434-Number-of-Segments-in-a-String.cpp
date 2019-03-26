    int countSegments(string s) {
        s += " ";
        int c(0);
        
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] != ' ' && s[i+1] == ' ') {
                c++;
            }
        }
        
        return c;
    }
