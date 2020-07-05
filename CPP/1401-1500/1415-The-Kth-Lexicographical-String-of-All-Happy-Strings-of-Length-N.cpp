class Solution {
public:
    bool check(string&s) {
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i-1]) return false;
        }
        return true;
    }
    void findNext(string& s, int& k, const int& n) {
        s.back()++;
        int i = n - 1;
        while (s[i] == 'd') {
            s[i--] = 'a';
            if (i == -1) {
                s.clear();
                return;
            }
            s[i]++;
        }
        //cout << s << endl;
        if (check(s)) k--;
    }
    string getHappyString(int n, int k) {
        string s(n, 'a');
        if (n == 1) k--;
        while (k) {
            findNext(s, k, n);
            if (s.empty()) break;
        }
        return s;
    }
};
