class Solution {
public:
    int numDupDigitsAtMostN(int n) {
        string s(to_string(n)), t, u;
        int ans(0), c(10), p(9);

        for (int i = 1; i < s.length(); ++i) {
            ans += p;
            --c;
            p *= c;
        }

        function<void(int, int, bool)> dfs = [&](int i, int mask, bool unbounded) {
            if (i == s.length()) {
                //cout << t << endl;
                ans++;
                return;
            }
            // unbounded: true , k whatever
            // unbounded: false, | k == s[i] - '0'
            for (int k = (i == 0); k <= (unbounded ? 9 : (s[i] - '0')); ++k) {
                if (!(mask & (1 << k))) {
                    t += '0' + k;
                    dfs(i + 1, mask | (1 << k), unbounded | (k != s[i] - '0'));
                    t.pop_back();
                }
            }
        };

        dfs(0, 0, false);
        return n - ans;
    }
};
