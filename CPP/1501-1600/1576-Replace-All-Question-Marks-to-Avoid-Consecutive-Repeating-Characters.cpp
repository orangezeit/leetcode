class Solution {
public:
    string modifyString(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '?') continue;
            s[i] = i && s[i - 1] == 'a' ? 'b' : 'a';
            if (i + 1 < s.length() && s[i + 1] == s[i]) {
                s[i]++;
                if (i && s[i - 1] == s[i]) s[i]++;
            }
        }
        return s;
    }
};
