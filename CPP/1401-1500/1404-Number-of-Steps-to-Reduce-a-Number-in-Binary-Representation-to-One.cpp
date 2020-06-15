class Solution {
public:
    int numSteps(string s) {
        int c(0);
        while (s != "1") {
            if (s.back() == '1') {
                s.back()++;
                for (int i = s.length() - 1; i >= 1; --i) {
                    if (s[i] == '2') {
                        s[i] = '0';
                        s[i-1]++;
                    }
                }
                if (s[0] == '2') {
                    s[0] = '0';
                    s.insert(s.begin(), '1');
                }
            } else {
                s.pop_back();
            }
            c++;
        }
        return c;
    }
};
