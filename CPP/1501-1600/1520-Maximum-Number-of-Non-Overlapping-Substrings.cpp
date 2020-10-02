class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        const int n = s.length();
        vector<int> l(26, n), r(26, -1);
        for (int i = 0; i < s.length(); ++i) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
        }
        function<int(int)> extend = [&](int i) {
            int p = r[s[i] - 'a'];
            for (int j = i; j <= p; ++j) {
                if (l[s[j] - 'a'] < i) return -1;
                p = max(p, r[s[j] - 'a']);
            }
            return p;
        };
        stack<long> res;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (i != l[s[i] - 'a']) continue;
            int p = extend(i);
            if (p == -1) continue;
            if (i > last) res.push(-1);
            res.top() = (long)i * n + (last = p);
        }
        vector<string> ans(res.size());
        for (int i = 0; i < ans.size(); ++i) {
            ans[i] = s.substr(res.top() / n, res.top() % n - res.top() / n + 1);
            res.pop();
        }
        return ans;
    }
};
