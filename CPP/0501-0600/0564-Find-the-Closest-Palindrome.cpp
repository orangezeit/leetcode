class Solution {
public:
    void compare(string s, string n, string& diff, string& ans) {
        string temp(s);
        if (s.length() < n.length() || s.length() == n.length() && s < n) swap(s, n);

        reverse(s.begin(), s.end());
        reverse(n.begin(), n.end());
        int i(0);
        for (i = 0; i < n.length(); ++i) {
            s[i] -= n[i] - '0';
            if (s[i] < '0') {
                s[i] += 10;
                s[i+1]--;
            }
        }
        while (i < s.length() - 1) {
            if (s[i] < '0') {
                s[i] += 10;
                s[i+1]--;
            }
            i++;
        }
        while (s.back() == '0') s.pop_back();
        reverse(s.begin(), s.end());
        if (diff.length() > s.length() || diff.length() == s.length() && diff > s) {
            ans = temp;
            diff = s;
        }
    }
    string nearestPalindromic(string n) {
        if (n.length() == 1) return n == "0" ? "1" : string(1, n[0] - 1);
        string res1(n.length(), ' ');
        for (int i = 0; i < n.length() / 2 + (n.length() % 2); ++i) {
            res1[n.length() - i - 1] = res1[i] = n[i];
        }
        string res2(res1), res3(res1);
        int k(n.length() / 2 - !(n.length() % 2));
        while (true) {
            res2[k]++;
            if (k != n.length()-1-k) res2[n.length()-1-k]++;
            if (res2[k] <= '9') break;
            res2[k] = res2[n.length()-1-k] = '0';
            k--;
            if (k < 0) {
                res2.insert(res2.begin(), '1');
                res2.pop_back();
                res2 += '1';
                break;
            }
        }

        k = n.length() / 2 - !(n.length() % 2);
        while (true) {
            res3[k]--;
            if (k != n.length()-1-k) res3[n.length()-1-k]--;
            if (res3[k] >= '0') break;
            res3[k] = res3[n.length()-1-k] = '9';
            k--;
        }

        if (res3[0] == '0') {
            res3.erase(res3.begin());
            res3.pop_back();
            res3.push_back('9');
        }

        vector<string> strs({res3, res1, res2});
        sort(strs.begin(), strs.end(),
             [](const string& s1, const string& s2){ return s1.length() < s2.length() || s1.length() == s2.length() && s1 < s2; });
        string ans, diff("1000000000000000000");
        for (string s: strs) {
            if (s == n) continue;
            compare(s, n, diff, ans);
        }
        return ans;
    }
};
