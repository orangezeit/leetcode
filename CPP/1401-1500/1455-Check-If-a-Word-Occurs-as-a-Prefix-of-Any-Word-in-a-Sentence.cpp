class Solution {
public:
    int isPrefixOfWord(string sentence, string sw) {
        istringstream iss(sentence);
        string word;
        int i(1);
        while (iss >> word) {
            if (word.find(sw) == 0) return i;
            i++;
        }
        return -1;
    }
};
