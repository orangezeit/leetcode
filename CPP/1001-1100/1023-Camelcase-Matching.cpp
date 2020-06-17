class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int j(0);
            bool matched(true);
            for (const char& c: queries[i]) {
                if (j < pattern.length() && c == pattern[j]) {
                    j++;
                } else if (c >= 'A' && c <= 'Z') {
                    matched = false;
                    break;
                }
            }
            ans[i] = matched && j == pattern.length();
        }
        return ans;
    }
};
