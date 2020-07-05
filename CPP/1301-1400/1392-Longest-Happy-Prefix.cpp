class Solution {
public:
    string longestPrefix(string s) {
        int n(s.length()), j(0), ans(0);
        vector<int> nxts({0, 0});
        for (int i = 1; i < n; ++i) {
            while (j && s[i] != s[j]) j = nxts[j];
            if (s[i] == s[j]) j++;
            nxts.push_back(j);
            ans = max(ans, j);
        }
        return s.substr(0, nxts.back());
    }
};
