    bool wordPattern(string pattern, string str) {
        str += " ";
        unordered_map<string, char> hashmap;
        unordered_set<char> hashset;
        int t(-1), k(0);
        
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ') {
                string word = str.substr(t+1, i-t-1);
                if (hashmap.find(word) == hashmap.end() && hashset.find(pattern[k]) == hashset.end()) {
                    hashmap[word] = pattern[k];
                    hashset.insert(pattern[k]);
                } else if (hashmap[word] != pattern[k]) {
                    return false;
                }
                k++;
                t = i;
            }
        }
        
        return k == pattern.length() && t == str.length()-1;
    }
