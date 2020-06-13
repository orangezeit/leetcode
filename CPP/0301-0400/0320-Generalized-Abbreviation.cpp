class Solution {
private:
    vector<string> words;

    string modified(string word) {
        string str;

        for (int i = 0; i < word.length(); ++i) {
            if (word[i] != '1') {
                str += word[i];
            } else {
                int c = 0;
                while (word[i] == '1') {
                    c++;
                    i++;
                    if (i == word.length())
                        return str + to_string(c);
                }

                str += to_string(c);
                i--;
            }
        }

        return str;
    }

public:
    void permutationHelper(string word, int p) {
        if (p == word.length()) {
            words.push_back(modified(word));
            return;
        }


        permutationHelper(word, p + 1);
        word[p] = '1';
        permutationHelper(word, p + 1);
    }

    vector<string> generateAbbreviations(string word) {
        permutationHelper(word, 0);
        return words;
    }
};
