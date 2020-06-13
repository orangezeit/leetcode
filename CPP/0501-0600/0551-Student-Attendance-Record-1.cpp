    bool checkRecord(string s) {
        int a(0);
        
        if (s.length() >= 2) {
            if (s[0] == 'A') {
                a++;
            }
            
            if (s.back() == 'A') {
                a++;
            }
            
            for (int i = 1; i < s.length()-1; ++i) {
                if ((s[i-1] == 'L' && s[i] == 'L' && s[i+1] == 'L') || a >= 2) {
                    return false;
                } else if (s[i] == 'A') {
                    a++;
                }
            }
        }
        
        return a < 2;
    }
