class Solution {
public:
    string sortString(string s) {
        int letters[26] = {};
        string t;

        for (const char& c: s) letters[c - 'a']++;

        while (true) {
            for (int i = 0; i < 26; ++i)
                if (letters[i]-- > 0)
                    t += 'a' + i;
            for (int i = 25; i >= 0; --i)
                if (letters[i]-- > 0)
                    t += 'a' + i;
            if (s.length() == t.length()) break;
        }
        return t;
    }
};
