class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> states(32, -2);
        states[0] = -1;
        const string vowels("aeiou");
        int ans(0), mask(0);

        for (int k = 0; k < s.length(); ++k) {
            for (int i = 0; i < 5; ++i) {
                if (s[k] == vowels[i]) {
                    mask ^= 1 << i;
                    break;
                }
            }
            states[mask] == -2 ? states[mask] = k : ans = max(ans, k - states[mask]);
        }

        return ans;
    }
};
