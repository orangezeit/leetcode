struct TrieNode {
    bool isWord;
    vector<TrieNode*> letters;
    TrieNode() : isWord(false) { letters.resize(26); }
};

class Solution {
public:
    TrieNode* tn = new TrieNode();
    vector<vector<string>> ans;
    int k;

    void buildTrie(const vector<string>& words) {
        for (const string& word: words) {
            TrieNode* temp = tn;
            for (const char& c: word) {
                if (!temp->letters[c - 'a'])
                    temp->letters[c - 'a'] = new TrieNode();
                temp = temp->letters[c - 'a'];
            }
            temp->isWord = true;
        }

    }

    void traverse(string& str, TrieNode* temp, vector<string>& options) {
        if (temp->isWord) {
            options.push_back(str);
            return;
        }
        for (int i = 0; i < 26; ++i)
            if (temp->letters[i]) {
                str += ('a' + i);
                traverse(str, temp->letters[i], options);
                str.pop_back();
            }
    }

    TrieNode* maker(string& prefix, const vector<string>& path) {
        int n = path.size();
        for (const string& s: path) prefix += s[n];
        int k = 0;
        TrieNode* temp = tn;

        while (temp && k < prefix.length())
            temp = temp->letters[prefix[k++] - 'a'];
        return temp;
    }

    void squareFinder(string& prefix, TrieNode* n, vector<string>& path) {

        vector<string> options;
        traverse(prefix, n, options);

        for (const string& opt: options) {
            path.push_back(opt);
            if (path.size() == k) {
                ans.push_back(path);
                path.pop_back();
                continue;
            }
            prefix.clear();
            TrieNode* temp = maker(prefix, path);
            if (temp)
                squareFinder(prefix, temp, path);
            path.pop_back();
        }
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        k = words[0].length();
        buildTrie(words);
        vector<string> p;
        string s;
        squareFinder(s, tn, p);
        return ans;
    }
};
