class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> list;
        int maxL(0), i(0);

        for (int j = 0; j < s.length(); ++j) {
            if (list.count(s[j]))
                while (s[i++] != s[j])
                    list.erase(s[i - 1]);
            else
                list.insert(s[j]);
            maxL = max(maxL, j - i + 1);
        }

        return maxL;
    }
};
