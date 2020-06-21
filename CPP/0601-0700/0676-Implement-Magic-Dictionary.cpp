class MagicDictionary {
private:
    unordered_map<int, vector<string>> d;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        d.clear();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const string& w: dict)
            d[w.length()].emplace_back(w);
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (const string& w: d[word.length()]) {
            int c = 0;
            for (int i = 0; i < w.length(); ++i)
                if (word[i] != w[i])
                    c++;
            if (c == 1) return true;
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
