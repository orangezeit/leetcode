class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        string num;
        int k(0);

        for (int i = 0; i < abbr.length(); ++i) {
            if (abbr[i] >= 'a' && abbr[i] <= 'z') {
                if (!num.empty()) {
                    if (num[0] == '0') return false;
                    k += stoi(num);
                    num.clear();
                }

                if (k > word.length()) return false;

                if (word[k] == abbr[i]) {
                    k++;
                } else {
                    return false;
                }

            } else {
                num += abbr[i];
            }
        }

        if (!num.empty()) {
            if (num[0] == '0') return false;
            k += stoi(num);
        }

        return k == word.length();
    }
};
