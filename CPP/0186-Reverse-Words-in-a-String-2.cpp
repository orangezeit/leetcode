class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int i(0), j(0);
        while (j < str.size()) {
            while (j < str.size() && str[j] != ' ') j++;
            reverse(str.begin() + i, str.begin() + j);
            i = ++j;
        }
    }
};
