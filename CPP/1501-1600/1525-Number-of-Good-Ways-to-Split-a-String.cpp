class Solution {
public:
    int numSplits(string s) {
        int left[26] = {}, right[26] = {};
        int l(0), r(0);
        for (const char& c: s)
            if (++right[c - 'a'] == 1)
                r++;
        s.pop_back();
        int ans(0);
        for (const char& c: s) {
            if (++left[c - 'a'] == 1)
                l++;
            if (--right[c - 'a'] == 0)
                r--;
            ans += (l == r);
        }
        return ans;
    }
};
