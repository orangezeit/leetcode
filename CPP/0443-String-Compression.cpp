    int compress(vector<char>& chars) {
        if (chars.size() <= 1) {
            return chars.size();
        }
        
        chars.push_back(NULL);
        int t(-1), l(0);
        
        for (int i = 0; i < chars.size()-1; ++i) {
            if (chars[i] != chars[i+1]) {
                chars[l++] = chars[i];
                if (i-t-1) {
                    string str = to_string(i-t);
                    for (int j = 0; j < str.length(); ++j) {
                        chars[l++] = str[j];
                    }
                }
                t = i;
            }
        }
        
        return l;
    }
