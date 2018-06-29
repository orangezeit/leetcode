    vector<string> findRepeatedDnaSequences(string s) {
        if (s.length() <= 10) {
            return vector<string>(0);
        }
        
        unordered_set<string> dict, repeat;
        string str = s.substr(0,10);
        dict.insert(str);
        
        for (int i = 10; i < s.length(); ++i) {
            str += s[i];
            str.erase(str.begin());
            if (dict.find(str) == dict.end()) {
                dict.insert(str);
            } else {
                repeat.insert(str);
            }
        }
        
        return vector<string>(repeat.begin(), repeat.end());
    }
