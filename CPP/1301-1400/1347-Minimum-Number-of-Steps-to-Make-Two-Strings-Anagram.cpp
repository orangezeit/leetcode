class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> letters(26);
        for (int i = 0; i < s.length(); ++i) {
            letters[s[i] - 'a']++;
            letters[t[i] - 'a']--;
        }
        int ans(0);
        for (int i = 0; i < 26; ++i) ans += abs(letters[i]);
        return ans / 2;
    }
};
