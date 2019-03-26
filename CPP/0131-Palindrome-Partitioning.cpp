private:
    unordered_map<string, bool> palindromes;
    vector<vector<string>> record;
    bool isPalindrome(string str) {
        if (palindromes.find(str) != palindromes.end()) {
            return palindromes[str];
        }
        
        string str_copy = str;
        reverse(str.begin(), str.end());
        palindromes[str] = str == str_copy;
        return str == str_copy;
    }
    
    void par(string s, vector<string> strs) {
        if (s.empty()) {
            record.push_back(strs);
        }
        
        for (int i = 0; i < s.length(); ++i) {
            if(isPalindrome(s.substr(0, i+1))) {
                strs.push_back(s.substr(0, i+1));
                par(s.substr(i+1, s.length()-i-1), strs);
                strs.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<string> strs;
        par(s, strs);
        return record;
    }
