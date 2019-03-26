    string reverseSubstr(string s) {
        for (int i = 0; i < s.length() / 2; ++i) {
            swap(s[i], s[s.length()-i-1]);
        }
        return s;
    }
    
    string reverseStr(string s, int k) {
        if (k >= s.length()) {
            return reverseSubstr(s); 
        } else {
            for (int i = 0; i < s.length(); i += 2*k) {
                if (i <= s.length() - k) {
                    s = s.substr(0,i) + reverseSubstr(s.substr(i, k)) + s.substr(i+k, s.length()-i-k);
                } else {
                    s = s.substr(0,i) + reverseSubstr(s.substr(i, s.length()-i));
                }
            }
            
            return s;
        }
    }
