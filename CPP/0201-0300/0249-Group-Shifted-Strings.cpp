class Solution {
public:
    bool matched(string str1, string str2) {
        if (str1.length() != str2.length())
            return false;
        
        for (int i = 0; i < str1.length() - 1; ++i) {
            if ((str1[i] - str2[i] + 26) % 26 != (str1[i+1] - str2[i+1] + 26) % 26)
                return false;
        }
        
        return true;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> patterns;
        
        for (int i = 0; i < strings.size(); ++i) {
            bool found = false;
            
            for (auto it = patterns.begin(); it != patterns.end(); ++it) {
                if (matched(it->first, strings[i])) {
                    found = true;
                    it->second.push_back(strings[i]);
                    break;
                }
            }
            
            if (!found) {
                patterns[strings[i]] = {strings[i]};
            }
        }
        
        vector<vector<string>> ans;
        
        for (auto it = patterns.begin(); it != patterns.end(); ++it) {
            ans.push_back(it->second);
        }
        
        return ans;
    }
};
