class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<vector<int>> abc(3);
        int ans(0);
        for (int i = 0; i < s.length(); ++i) {
            abc[s[i] - 'a'].emplace_back(i);
        }
        for (int i = 0; i < s.length(); ++i) {
            int x((s[i] - 'a' + 1) % 3), y((s[i] - 'a' + 2) % 3);
            auto lx(lower_bound(abc[x].begin(), abc[x].end(), i + 1));
            auto ly(lower_bound(abc[y].begin(), abc[y].end(), i + 1));
            if (lx != abc[x].end() && ly != abc[y].end()) {
                ans += s.length() - max(*lx, *ly);
            }
        }
        return ans;
    }
};
