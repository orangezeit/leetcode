class Solution {
public:
    unordered_map<string, bool> rec;
    bool canWin(string s) {
        if (rec.count(s)) return rec[s];
        //if (s.length() < 2) return false;
        bool test = false;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '+' && s[i - 1] == '+') {
                s[i - 1] = '-';
                s[i] = '-';
                test |= !canWin(s);
                s[i - 1] = '+';
                s[i] = '+';
            }
        }
        rec[s] = test;
        return test;
    }
};
