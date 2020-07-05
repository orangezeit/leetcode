class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> cnts;
        for (int i = 0; i + k - 1 < s.length(); ++i)
            cnts.insert(s.substr(i, k));
        return cnts.size() == (1 << k);
    }
};
