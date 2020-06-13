    int titleToNumber(string s) {
        int num(0);
        
        for (int i = 0; i < s.length(); ++i) {
            num += (s[i]-'A'+1) * pow(26, s.length()-i-1);
        }
        
        return num;
    }
