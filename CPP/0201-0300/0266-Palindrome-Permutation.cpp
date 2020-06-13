class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> counter;

        for (int i = 0; i < s.length(); ++i) {
            counter[s[i]]++;
        }

        int k = 0;

        for (auto it = counter.begin(); it != counter.end(); ++it) {
            if (it->second % 2)
                k++;
            if (k > 1)
                return false;
        }

        return true;
    }
};
