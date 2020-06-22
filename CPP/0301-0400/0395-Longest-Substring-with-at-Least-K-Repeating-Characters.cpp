class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length() < k) return 0;

        int letters[26] = {};

        for (const char& c: s)
            letters[c - 'a']++;

        for (int i = 0; i < 26; ++i) {
            if (letters[i] && letters[i] < k) break;
            if (i == 25) return s.length();
        }
        //cout << "aha";
        string t;
        int res(0);

        for (const char& c: s) {
            //if ()
            if (letters[c - 'a'] < k) {
                res = max(res, longestSubstring(t, k));
                t.clear();
            } else {
                t += c;
            }
        }
        res = max(res, longestSubstring(t, k));
        return res;
    }
};
