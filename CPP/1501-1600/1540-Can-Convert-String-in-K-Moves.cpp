class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        int n(s.length()), changes[26] = {};
        for (int i = 0; i < n; ++i) {
            int x = (t[i] - s[i] + 26) % 26;
            if (x == 0) continue;
            if (26 * changes[x]++ + x > k) return false;
        }
        return true;
    }
};
