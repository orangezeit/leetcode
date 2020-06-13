class ValidWordAbbr {
public:
    unordered_map<string, unordered_map<int, int>> occurred;
    unordered_set<string> dict;

    ValidWordAbbr(vector<string>& dictionary) {
        for (const string& word: dictionary) {
            if (word.length() < 2) continue;
            string str;
            str += word[0];
            str += word.back();
            occurred[str][word.length() - 2]++;
            dict.insert(word);
        }
    }

    bool isUnique(string word) {
        if (word.length() < 2) return true;
        string str;
        str += word[0];
        str += word.back();
        if (!occurred.count(str)) return true;
        if (!occurred[str].count(word.length() - 2)) return true;
        if (occurred[str][word.length() - 2] > 1) return false;
        return dict.count(word);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */
