    bool allNumDecimal(string s, bool decimal) {
        if (s.empty()) {
            return false;
        }
        
        if (s[0] == '-' || s[0] == '+') {
            s.erase(s.begin());
        }
        
        bool point = true;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] < '0' || s[i] > '9') {
                if (s[i] == '.' && decimal && point) {
                    point = false;
                } else {
                    return false;
                }
            }
        }
        
        return !s.empty() && s != ".";
    }
    
    
    bool isNumber(string s) {
        while (s.back() == ' ') {
            s.pop_back();
            if (s.empty()) {
                return false;
            }
        }
        
        while (s[0] == ' ') {
            s.erase(s.begin());
            if (s.empty()) {
                return false;
            }
        }
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == 'e') {
                return allNumDecimal(s.substr(0, i), true) && allNumDecimal(s.substr(i+1, s.length()-i-1), false);
            }
        }
        
        return allNumDecimal(s, true);
    }
