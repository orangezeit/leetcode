class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> dict;
        for (int i = 0; i < 26; ++i)
            dict[keyboard[i]] = i;
        int pos(0), t(0);
        for (int i = 0; i < word.length(); ++i) {
            t += abs(dict[word[i]] - pos);
            pos = dict[word[i]];
        }
        return t;
    }
};
