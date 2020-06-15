class Solution {
public:
    int maxPower(string s) {
        int ans(1), k(0);
        s += '*';
        for (int i = 0; i + 1 < s.length(); ++i) {
            if (s[i] != s[i+1]) {
                ans = max(ans, i + 1 - k);
                k = i + 1;
            }
        }
        return ans;
    }
};
