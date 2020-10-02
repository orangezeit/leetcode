class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (const char& c: s)
            !ans.empty() && abs(ans.back() - c) == 32 ? ans.pop_back() : ans.push_back(c);
        return ans;
    }
};
