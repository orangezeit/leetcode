struct TrieNode {
    bool marked;
    unordered_map<char, TrieNode*> branchs;
    TrieNode(): marked(false), branchs() {}
};

class StreamChecker {
public:
    TrieNode* dict = new TrieNode();
    TrieNode* search = dict;
    string str;
    int maxLen;

    StreamChecker(vector<string>& words) {
        maxLen = 0;
        for (string& word: words) {
            maxLen = max(maxLen, (int)word.length());
            TrieNode* temp = dict;
            reverse(word.begin(), word.end());
            for (const char& c: word) {
                if (!temp->branchs.count(c))
                    temp->branchs[c] = new TrieNode();
                temp = temp->branchs[c];
            }
            temp->marked = true;
        }
    }

    bool query(char letter) {
        str += letter;
        if (str.length() > maxLen) str.erase(str.begin());
        //cout << str.length() << endl;
        for (int i = str.length() - 1; i >= 0; --i) {
            //cout << str[i];
            if (!search->branchs.count(str[i])) {
                search = dict;
                return false;
            }
            search = search->branchs[str[i]];
            if (search->marked) {
                search = dict;
                return true;
            }
        }
        //cout << endl;
        search = dict;
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
