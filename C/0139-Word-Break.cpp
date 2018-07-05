private:
    unordered_map<string, bool> record;
public:
    bool inDict(string s, vector<string> wordDict) {
        for (int i = 0; i < wordDict.size(); ++i) {
            if (s == wordDict[i]) {
                record[s] = true;
                return true;
            }
        }
        record[s] = false;
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty()) {
            return true;
        }
        
        bool initial = false;
        
        for (int i = 0; i < s.length(); ++i) {
            if (record.find(s.substr(i, s.length()-i)) != record.end()) {
                initial |= (wordBreak(s.substr(0,i), wordDict) && record[s.substr(i, s.length()-i)]);
            } else {
                initial |= (wordBreak(s.substr(0,i), wordDict) && inDict(s.substr(i, s.length()-i), wordDict));
            }
        }
        
        return initial;
    }
