class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.empty()) return 0;
        int res(0), prev(1), endwith[26]({});
        endwith[p[0] - 'a'] = 1;
        for (int i = 1; i < p.length(); ++i) {
            prev = p[i - 1] == 'z' && p[i] == 'a' || p[i - 1] == p[i] - 1 ? prev + 1 : 1;
            endwith[p[i] - 'a'] = max(endwith[p[i] - 'a'], prev);
        }
        return accumulate(endwith, endwith + 26, 0);
    }
};
