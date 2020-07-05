class Solution {
public:
    int maxVowels(string s, int k) {
        int rec[26] = {};
        // 0, 4, 8, 14, 20
        for (int i = 0; i < k; ++i) {
            rec[s[i] - 'a']++;
        }
        int ans = rec[0] + rec[4] + rec[8] + rec[14] + rec[20];
        for (int i = k; i < s.length(); ++i) {
            rec[s[i-k] - 'a']--;
            rec[s[i] - 'a']++;
            ans = max(ans, rec[0] + rec[4] + rec[8] + rec[14] + rec[20]);
        }
        return ans;
    }
};
