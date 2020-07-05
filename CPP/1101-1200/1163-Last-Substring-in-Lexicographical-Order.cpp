
class Solution {
public:
    string lastSubstring(string s) {
        int i(0), j(1), k(0);
        while (j + k < s.length()) {
            if (s[i + k] == s[j + k]) {
                k++;
                continue;
            } else if (s[i + k] > s[j + k]) {
                j += k + 1;
            } else {
                i += k + 1;
            }
            if (i == j) j++;
            k = 0;
        }
        return s.substr(i);
    }
};
