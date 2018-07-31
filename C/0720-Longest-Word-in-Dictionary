    string longestWord(vector<string>& words) {
        words.push_back("");
        unordered_set<string> wordset(words.begin(), words.end());
        string str, longstr;
        bool add = true;
        
        sort(words.begin(), words.end());
        words.push_back("STOP");
        
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i+1].substr(0, words[i+1].length()-1) == words[i] && add) {
                str = words[i+1];
            } else {
                if (str.length() > longstr.length()) longstr = str;
                
                if(wordset.find(words[i+1].substr(0, words[i+1].length()-1)) != wordset.end()) {
                    str = words[i+1];
                    add = true;
                } else {
                    wordset.erase(words[i+1]);
                    add = false;
                }
            }
        }
        
        return longstr;
    }
