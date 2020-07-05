class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // Time Complexity: O(3^N - 4^N)
        // Space Complexity: O(3^N - 4^N)
        vector<string> ans;
        if (digits.empty()) return ans;

        const vector<string> dict({"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string str;

        function<void(const int&, string&)> dfs = [&](const int& i, string& s){
            if (i == digits.size()) {
                ans.emplace_back(s);
                return;
            }
            for (const char& c: dict[digits[i] - '2']) {
                s += c;
                dfs(i + 1, s);
                s.pop_back();
            }
        };
        dfs(0, str);
        return ans;
    }
};
