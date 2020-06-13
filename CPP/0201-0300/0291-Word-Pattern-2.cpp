class Solution {
public:
    void backtrack(unordered_map<char, string>& dict, const string& pattern, int pos1, const string& str, int pos2, bool& hasPattern) {
        if (pos1 == pattern.length() && pos2 == str.length()) {
            unordered_set<string> ss;

            for (auto& p: dict) {
                if (ss.count(p.second)) {
                    return;
                } else {
                    ss.insert(p.second);
                }
            }

            hasPattern = true;
        } else if (pos1 != pattern.length() && pos2 != str.length()) {
            char c = pattern[pos1];
            if (dict.count(c)) {
                if (dict[c] == str.substr(pos2, dict[c].length())) {
                    backtrack(dict, pattern, pos1 + 1, str, pos2 + dict[c].length(), hasPattern);
                }
            } else {
                string s;
                for (int len = 1; len <= str.length() - pos2; ++len) {
                    //string t = ;
                    s += str[pos2 + len - 1];
                    dict[c] = s;
                    backtrack(dict, pattern, pos1 + 1, str, pos2 + len, hasPattern);
                    dict.erase(c);
                }
            }
        }
    }
    bool wordPatternMatch(string pattern, string str) {
        bool hasPattern(false);
        unordered_map<char, string> dict;
        backtrack(dict, pattern, 0, str, 0, hasPattern);
        return hasPattern;
    }
};
