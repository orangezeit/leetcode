    bool isMatch(string s, string p) {
        if (s.empty() && p.empty()) {
            return true;
        } else if (s.empty()) {
            while (p.back() == '*') {
                p.pop_back();
                p.pop_back();
                if (p.empty()) {
                    return true;
                }
            }
            return false;
        } else if (s.back() == p.back() || p.back() == '.') {
            s.pop_back();
            p.pop_back();
            return isMatch(s, p);
        } else if (p.back() == '*') {
            p.pop_back();
            char c = p.back();
            p.pop_back();
            bool prev = !p.empty();
            int ip = 1;
            
            if (!p.empty()) {
                while (c == p[p.length()-ip]) {
                    ip++;
                    if (ip > p.length()) {
                        prev = false;
                        break;
                    }
                }
            }
            
            if (prev) {
                if (c == '.') {
                    for (int i = 0; i <= s.length(); ++i) {
                        if (isMatch(s.substr(0, i), p)) {
                            return true;
                        }
                    }
                    return false;
                } else {
                    int is = 1;
                    
                    while (s[s.length()-is] == c) {
                        is++;
                    }
                    
                    if (is < ip) {
                        return false;
                    } else {
                        while (is >= ip) {
                            if (isMatch(s, p)) {
                                return true;
                            }
                            s.pop_back();
                            is--;
                        }
                        return false;
                    }
                }
            } else {
                if (c == '.') {
                    return s.length() >= p.length();
                } else {
                    return s.length() >= p.length() && s == string(s.length(), c);
                }
            }
        } else {
            return false;
        }
    }
