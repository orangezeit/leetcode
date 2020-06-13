    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashmap;
        unordered_set<char> hashset;
        
        for (int i = 0; i < s.length(); ++i) {
            if (hashmap.find(s[i]) == hashmap.end() && hashset.find(t[i]) == hashset.end()) {
                hashmap[s[i]] = t[i];
                hashset.insert(t[i]);
            } else if (hashmap[s[i]] != t[i]) {
                return false;
            }
        }
        
        return true;
    }
