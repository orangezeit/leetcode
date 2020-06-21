class Solution {
public:
    bool verify(vector<char> letters_S, vector<int> nums_S, string word) {
        vector<char> letters_word;
        vector<int> nums_word;

        int k = -1;

        for (int i = 0; i < word.length()-1; ++i) {
            if (word[i] != word[i+1]) {
                letters_word.push_back(word[i]);
                nums_word.push_back(i-k);
                k = i;
            }
        }

        letters_word.push_back(word[word.length()-1]);
        nums_word.push_back(word.length()-k-1);

        if (letters_S == letters_word) {
            for (int i = 0; i < nums_word.size(); ++i) {
                if ((nums_S[i] < nums_word[i]) || (nums_word[i] == 1 && nums_S[i] == 2)) {
                    return false;
                }
            }

            return true;
        } else {
            return false;
        }
    }
    int expressiveWords(string S, vector<string>& words) {
        int cnt = 0;

        if (S.length() == 0) {
            for (int i = 0; i < words.size(); ++i) {
                if (words[i].length() == 0) {
                    cnt++;
                }
            }

            return cnt;
        }

        vector<char> letters_S;
        vector<int> nums_S;

        int k = -1;

        for (int i = 0; i < S.length()-1; ++i) {
            if (S[i] != S[i+1]) {
                letters_S.push_back(S[i]);
                nums_S.push_back(i-k);
                k = i;
            }
        }

        letters_S.push_back(S[S.length()-1]);
        nums_S.push_back(S.length()-k-1);

        for (int i = 0; i < words.size(); ++i) {
            if (words[i].length() != 0) {
                if (verify(letters_S, nums_S, words[i])) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
