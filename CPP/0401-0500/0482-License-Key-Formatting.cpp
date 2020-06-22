class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        queue<char> q;
        for (const int& c: s) {
            if (c != '-')
                q.push(c);
        }
        while (!q.empty()) {
            int s = q.size() % k;
            for (int i = 0; i < (s ? s : k); ++i) {
                ans += toupper(q.front());
                q.pop();
            }
            ans += '-';
        }
        if (!ans.empty()) ans.pop_back();
        return ans;
    }
};
