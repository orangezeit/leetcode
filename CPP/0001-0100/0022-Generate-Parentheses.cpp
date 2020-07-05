class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Time Complexity: O(2^N)
        // Space Complexity: O(2^N)
        vector<string> ans;
        string str;
        function<void(const int&, string&)> generate = [&](const int& i, string& s) {
            if (s.length() == 2 * n) {
                if (!i) ans.emplace_back(s);
                return;
            }
            if (i <= n) {
                s += '(';
                generate(i + 1, s);
                s.pop_back();
            }
            if (i) {
                s += ')';
                generate(i - 1, s);
                s.pop_back();
            }
        };
        generate(0, str);
        return ans;
    }
};
