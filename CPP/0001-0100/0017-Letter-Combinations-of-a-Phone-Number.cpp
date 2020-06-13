class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        const vector<string> dict({"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string str;

        function<void(const int&, string&)> dfs = [&](const int& i, string& s){
            if (i == digits.size()) {
                ans.push_back(s);
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
