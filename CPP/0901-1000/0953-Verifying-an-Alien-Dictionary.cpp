class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int letters[26] = {};
        for (int i = 0; i < 26; ++i)
            letters[order[i] - 'a'] = i;
        auto compare = [&](const string& s, const string& t) {
            for (int i = 0; i < min(s.length(), t.length()); ++i) {
                if (letters[s[i] - 'a'] == letters[t[i] - 'a']) continue;
                return letters[s[i] - 'a'] < letters[t[i] - 'a'];
            }
            return s.length() < t.length();
        };
        for (int i = 1; i < words.size(); ++i) {
            if (!compare(words[i-1], words[i]))
                return false;
        }
        return true;
    }
};
