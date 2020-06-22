class Solution {
public:
    int needTypes(const string& s) {
        int lc(0), uc(0), d(0);
        for (char c: s) {
            if (c >= 'a' && c <= 'z') {
                lc = 1;
            } else if (c >= 'A' && c <= 'Z') {
                uc = 1;
            } else if (c >= '0' && c <= '9') {
                d = 1;
            }
        }
        return 3 - lc - uc - d;
    }
    vector<int> findLens(string& s) {
        s += ' ';
        int k(-1);
        vector<int> ls;

        for (int i = 0; i + 1< s.length(); ++i) {
            if (s[i] != s[i+1]) {
                if (i - k >= 3) ls.push_back(i - k);
                k = i;
            }
        }
        s.pop_back();
        return ls;
    }
    int strongPasswordChecker(string s) {
        int n(s.length());
        int nt = needTypes(s);
        vector<int> lens = findLens(s);
        if (s.length() < 6) {
            return max(nt, 6 - n);
        } else if (n >= 6 && n <= 20) {
            int sc(0);
            for (int& l: lens) sc += l / 3;
            return max(sc, nt);
        } else {
            int i(0), needRemove(n - 20);
            while (i < lens.size() && needRemove) {
                if (lens[i] % 3 == 0) {
                    needRemove--;
                    lens[i]--;
                }
                i++;
            }
            i = 0;
            while (i < lens.size() && needRemove) {
                if (lens[i] % 3 == 1 && needRemove > 1) {
                    needRemove -= 2;
                    lens[i] -= 2;
                }
                i++;

            }
            i = 0;
            while (i < lens.size() && needRemove) {
                while (lens[i] >= 3 && needRemove >= 3) {
                    lens[i] -= 3;
                    needRemove -= 3;
                }
                i++;
            }
            int sc(0);
            for (int& l: lens) sc += l / 3;
            return max(sc, nt) + n - 20;
        }
        return -1;
    }

};
