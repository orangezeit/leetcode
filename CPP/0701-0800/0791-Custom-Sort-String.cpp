class Solution {
public:
    string customSortString(string s, string t) {
        int letters[26] = {};
        string str;

        for (const char& c: t)
            letters[c - 'a']++;

        for (const char& c: s) {
            str += string(letters[c - 'a'], c);
            letters[c - 'a'] = 0;
        }

        for (int i = 0; i < 26; ++i)
            str += string(letters[i], 'a' + i);

        return str;
    }
};
