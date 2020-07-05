class Solution {
public:
    bool isPalindrome(const string& s) {
        int i(0), j(s.length() - 1);
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
    int removePalindromeSub(string s) {
        return s.empty() ? 0 : isPalindrome(s) ? 1 : 2;
    }
};
