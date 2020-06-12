class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> rec;
        int k(0), len(0);
        
        for (int i = 0; i < s.length(); ++i) {
            rec[s[i]]++;
                while (rec.size() > 2) {
                    rec[s[k]]--;
                    if (!rec[s[k]]) rec.erase(s[k]);
                    k++;
                }
            
            len = max(len, i - k + 1);
        }
        
        return len;
    }
};
