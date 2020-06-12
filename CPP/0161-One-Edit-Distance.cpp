class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.length() < t.length()) swap(s, t);
        if (s.length() - t.length() >= 2) return false;
        if (s.length() == t.length()) {
            int k = 0;
            for (int i = 0; i < s.length(); ++i) {
                if (s[i] != t[i]) k++;
                if (k > 1) return false;
            }
            return k;
        } else {
            for (int i = 0; i < s.length(); ++i) {
                string temp = s;
                temp.erase(i, 1);
                if (temp == t) return true;
            }
            return false;
        }
    }
};
