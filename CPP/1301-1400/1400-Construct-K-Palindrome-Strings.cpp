class Solution {
public:
    bool canConstruct(string s, int k) {
        int letters[26] = {};
        for (const char& c: s) letters[c - 'a']++;
        int odds(0);
        for (int i = 0; i < 26; ++i) odds += letters[i] % 2;
        return s.length() >= k && odds <= k;
    }
};
