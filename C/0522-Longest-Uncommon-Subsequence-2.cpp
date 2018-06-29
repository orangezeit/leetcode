    int maxLength(vector<string> strs) {
        int l(0);
        for (int i = 0; i < strs.size(); ++i) {
            if (l < strs[i].length()) {
                l = strs[i].length();
            }
        }
        return l;
    }
    
    bool isSubsequence(string str1, string str2, int px, int py) {
        if (str2.length() > str1.length()) {
            return false;
        } else {
            if (py == -1) {
                return true;
            } else if (px == -1) {
                return false;
            } else {
                if (str1[px] == str2[py]) {
                    return isSubsequence(str1, str2, px-1, py-1);
                } else {
                    return isSubsequence(str1, str2, px-1, py);
                }
            }
        }
    }
    
    int measure(vector<string> strs) {
        bool hasequal = false;
        vector<string> repeated, nonrepeated;
        strs.push_back("!");
        
        for (int i = 0; i < strs.size()-1; ++i) {
            if (strs[i] == strs[i+1]) {
                hasequal = true;
                if (repeated.empty()) {
                    repeated.push_back(strs[i]);
                } else if (repeated.back() != strs[i]) {
                    repeated.push_back(strs[i]);
                }
            } else {
                if (repeated.empty()) {
                    nonrepeated.push_back(strs[i]);
                } else if (repeated.back() != strs[i]) {
                    nonrepeated.push_back(strs[i]);
                }
            }
        }
        
        if (!hasequal) {
            return maxLength(strs);
        } else {
            int l(-1);
            
            for (int i = 0; i < nonrepeated.size(); ++i) {
                for (int j = 0; j < repeated.size(); ++j) {
                    if (isSubsequence(repeated[j], nonrepeated[i], repeated[j].length()-1, nonrepeated[i].length()-1)) {
                        break;
                    }
                    
                    if (j == repeated.size()-1) {
                        int s = nonrepeated[i].length();
                        l = max(l, s);
                    }
                }
            }
            
            return l;
        }
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        return measure(strs);
    }
