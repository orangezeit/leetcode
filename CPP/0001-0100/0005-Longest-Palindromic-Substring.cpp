class Solution {
public:
    string longestPalindrome(string s) {
        int first(0), len(1);

        for (int i = 0; i + 1 < s.length(); ++i) {
            int left(i), right(i);
            while (--left >= 0 && ++right < s.length() && s[left] == s[right])
                if (right - left + 1 > len) {
                    first = left;
                    len = right - left + 1;
                }
            left = i + 1;
            right = i;
            while (--left >= 0 && ++right < s.length() && s[left] == s[right])
                if (right - left + 1 > len) {
                    first = left;
                    len = right - left + 1;
                }
        }
        return s.empty() ? s : s.substr(first, len);
    }
};
