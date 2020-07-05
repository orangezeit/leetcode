class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt(0), ans(0);
        for (const char& c: s) {
            c == 'L' ? cnt++ : cnt--;
            if (!cnt) ans++;
        }

        return ans;
    }
};
