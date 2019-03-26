    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].length() != pattern.length()) continue;
            
            vector<int> forward(26, -1), backward(26, -1);
            bool followed = true;
            
            for (int j = 0; j < words[i].length(); ++j) {
                if (forward[words[i][j] - 'a'] == -1 && backward[pattern[j] - 'a'] == -1) {
                    forward[words[i][j] - 'a'] = pattern[j] - 'a';
                    backward[pattern[j] - 'a'] = words[i][j] - 'a';
                } else if (forward[words[i][j] - 'a'] != pattern[j] - 'a' || backward[pattern[j] - 'a'] != words[i][j] - 'a') {
                    followed = false;
                    break;
                }
            }
            
            if (followed) res.push_back(words[i]);
        }
        
        return res;
    }
