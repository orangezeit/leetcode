class Solution {
public:
    int minInsertions(string s) {
        vector<int> v;
        int prev = -1;
        s += '#';
        for (int i = 0; i + 1 < s.length(); ++i)
            if (s[i] != s[i + 1]) {
                v.emplace_back((s[i] == '(' ? -1 : 1) * (i - prev));
                prev = i;
            }

        int ans = 0, bal = 0;
        for (int& t : v) {
            if (t % 2 == 1) {
                ans++;
                t++;
            }
            bal -= t < 0 ? t : t / 2;
            if (bal < 0) {
                ans -= bal;
                bal = 0;
            }
        }

        return ans + bal * 2;
    }
};
