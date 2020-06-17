class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1(str1.length()), s2(str2.length());
        for (int i = gcd(s1, s2); i >= 1; --i) {
            if (s1 % i || s2 % i) continue;
            bool test(true);
            for (int j = 0; j < i; ++j) {
                if (str1[j] != str2[j]) {
                    test = false;
                    break;
                }
                for (int k = 1; k < s1 / i; ++k) {
                    if (str1[j] != str1[k * i + j]) {
                        test = false;
                        break;
                    }
                }
                for (int k = 1; k < s2 / i && test; ++k) {
                    if (str2[j] != str2[k * i + j]) {
                        test = false;
                        break;
                    }
                }
                if (!test) break;
            }

            if (test) return str1.substr(0, i);
        }

        return "";
    }
};
