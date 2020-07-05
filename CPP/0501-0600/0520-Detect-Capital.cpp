class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = count_if(word.begin(), word.end(), ::isupper);
        return n == 0 || (n == 1 && isupper(word[0])) || n == word.length();
    }
};
