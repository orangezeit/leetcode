class Solution {
public:
    string crackSafe(int n, int k) {
        const int total = pow(k, n);
        string ans(n, '0');
        unordered_set<string> visited({ans});

        function<bool(string&)> dfs = [&](string& s) {
            if (visited.size() == total) return true;
            string node = s.substr(s.length() - n + 1, n - 1);

            for (char c = '0'; c < '0' + k; ++c) {
                node += c;
                if (!visited.count(node)) {
                    s += c;
                    visited.insert(node);
                    if (dfs(s)) return true;
                    visited.erase(node);
                    s.pop_back();
                }
                node.pop_back();
            }
            return false;
        };

        return dfs(ans) ? ans : "";
    }
};
