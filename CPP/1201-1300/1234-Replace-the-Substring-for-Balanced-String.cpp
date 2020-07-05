class Solution {
public:
    int balancedString(string s) {
        int i(0), ans(s.length());
        int c(s.length()/4);
        unordered_map<char, int> m;

        for (char c: s) m[c]++;

        for (int j = 0; j < s.length(); ++j) {
            m[s[j]]--;
            while (i < s.length() && m['Q'] <= c && m['W'] <= c && m['E'] <= c && m['R'] <= c) {
                ans = min(ans, j-i+1);
                m[s[i++]]++;
            }
        }

        return ans;
    }
};
