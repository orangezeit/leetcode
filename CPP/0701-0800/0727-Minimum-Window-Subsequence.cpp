class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        int j(0), ml(s.length() + 1);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == t[j]) {
                if (++j == t.length()) {
                    int k(i);
                    --j;
                    while (i >= 0 && j >= 0) {
                        if (s[i--] == t[j]) --j;
                    }
                    i++;
                    j++;
                    //cout << k << endl;
                    if (k - i + 1 < ml) {
                        ans = s.substr(i, k - i + 1);
                        ml = k - i + 1;
                    }
                }
            }
        }
        return ans;
    }
};
