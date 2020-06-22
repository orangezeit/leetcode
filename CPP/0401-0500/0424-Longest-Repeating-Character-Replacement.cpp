class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<bool> letters(26, false);
        int ans(0);

        for (const char& c: s)
            letters[c - 'A'] = true;

        for (int c = 0; c < 26; ++c) {
            if (letters[c]) {
                int i(0);
                int num(k);
                int maxLen(0);

                for (int j = 0; j < s.length(); ++j) {
                    if (s[j] - 'A' != c) {
                        if (!(num && num--))
                            while (s[i++] - 'A' == c) {}
                    }
                    maxLen = max(j - i + 1, maxLen);
                }

                ans = max(maxLen, ans);
            }
        }

        return ans;
    }
};
