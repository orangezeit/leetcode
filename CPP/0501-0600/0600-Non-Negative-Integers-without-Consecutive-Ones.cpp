class Solution {
public:
    int findIntegers(int num) {
        string s;
        while (num) {
            s += '0' + num % 2;
            num /= 2;
        }
        int n(s.length());
        vector<int> a(n), b(n);
        a[0] = b[0] = 1;
        // a->0, b->1
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + b[i - 1];
            b[i] = a[i - 1];
        }

        int result = a[n - 1] + b[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] == '1' && s[i + 1] == '1') break;
            if (s[i] == '0' && s[i + 1] == '0') result -= b[i];
        }

        return result;
    }
};
