class Solution {
public:
    vector<int> partitionLabels(string s) {
        int i(-1), first[26] = {}, second[26] = {};
        vector<int> res;

        for (const char& c: s)
            first[c - 'a']++;

        for (int j = 0; j < s.length(); ++j) {
            bool part = true;
            first[s[j] - 'a']--;
            second[s[j] - 'a']++;

            for (int k = 0; k < 26; ++k)
                if (!(part &= !(first[k] && second[k])))
                    break;

            if (part) {
                res.push_back(j - i);
                i = j;
            }
        }

        return res;
    }
};
