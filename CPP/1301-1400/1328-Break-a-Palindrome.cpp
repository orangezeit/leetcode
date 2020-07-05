class Solution {
public:
    string breakPalindrome(string p) {
        int n(p.length());
        string str;
        bool ne(true);
        for (int i = 0; i < n / 2; ++i) {
            if (p[i] != 'a') {
                char tmp = p[i];
                p[i] = 'a';
                return p;
                //p[i] = tmp;
            } else if (ne) {
                ne = false;
                p[n - 1 - i] = 'b';
                str = p;
                p[n - 1 - i] = 'a';
            }

        }

        return str;
    }
};
