class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {

        unordered_map<string, int> rec;

        for (int i = 0; i < s.length(); ++i) {
            unordered_set<char> cs;
            string str;

            int j = i;
            while (j - i + 1 <= maxSize && j < s.length()) {
                cs.insert(s[j]);
                str += s[j];
                if (++j - i >= minSize && cs.size() <= maxLetters) rec[str]++;
            }
        }

        int ans(0);
        for (const auto& p: rec) ans = max(ans, p.second);
        return ans;
    }
};
