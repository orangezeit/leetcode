class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans(0);
        vector<int> secs(1, 1);
        for (int i = 1; i < s.length(); ++i) {
            if (s[i - 1] != s[i]) secs.emplace_back(0);
            secs.back()++;
        }
        for (int i = 1; i < secs.size(); ++i)
            ans += min(secs[i - 1], secs[i]);
        return ans;
    }
};
