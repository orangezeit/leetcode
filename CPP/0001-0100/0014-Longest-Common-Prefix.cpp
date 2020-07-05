class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Time Complexity: O(NL)
        // Space Complexity: O(1) for searching, O(L) for building string
        if (strs.empty()) return "";
        size_t k(INT_MAX), j(0);

        for (const string& s: strs)
            k = min(k, s.length());

        while (j < k) {
            for (int i = 0; i < strs.size() - 1; ++i)
                if (strs[i][j] != strs[i+1][j])
                    return strs[0].substr(0, j);
            j++;
        }

        return strs[0].substr(0, j);
    }
};
