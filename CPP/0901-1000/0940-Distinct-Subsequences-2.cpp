class Solution {
public:
    int distinctSubseqII(string S) {
        int mod(1e9 + 7), endWith[26] = {};
        for (const char& c: S)
            endWith[c - 'a'] = accumulate(endWith, endWith + 26, 1L) % mod;
        return accumulate(endWith, endWith + 26, 0L) % mod;
    }
};
