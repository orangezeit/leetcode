class Solution {
public:
    int maxDiff(int num) {
        string s(to_string(num));
        char c1(' '), c2(' '), e;
        string num1(s), num2(s);

        for (int i = 0; i < s.length(); ++i) {
            if (c1 != ' ') {
                if (s[i] == c1)
                    num1[i] = e;
            } else if (s[0] != '1') {
                num1[0] = e = '1';
                c1 = s[0];
            } else if (s[i] != '0' && s[i] != s[0]) {
                num1[i] = e = '0';
                c1 = s[i];
            }

            if (c2 != ' ') {
                if (s[i] == c2)
                    num2[i] = '9';
            } else if (s[i] != '9') {
                num2[i] = '9';
                c2 = s[i];
            }
        }

        return stoi(num2) - stoi(num1);
    }
};
