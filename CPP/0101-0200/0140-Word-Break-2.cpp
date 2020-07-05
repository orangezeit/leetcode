class Solution {
public:
    vector<string> ans, segs;
    vector<bool> marks;

    bool dfs(const unordered_set<string>& words, const string& s, int curr) {
        if (curr == s.length()) {
            string str;
            for (const string& seg: segs) str += seg + ' ';
            str.pop_back();
            ans.push_back(str);
            return true;
        }

        if (!marks[curr]) return false;

        string str;
        bool test = false;

        for (int i = curr; i < s.length(); ++i) {
            str += s[i];
            if (words.count(str)) {
                segs.push_back(str);
                test |= dfs(words, s, i + 1);
                segs.pop_back();
            }
        }

        return marks[curr] = test;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        marks.resize(s.length(), true);

        unordered_set<char> letters(s.begin(), s.end());
        for (const string& word: wordDict)
            for (const char& c: word)
                if (letters.count(c))
                    letters.erase(c);
        if (!letters.empty()) return ans;
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        dfs(words, s, 0);
        return ans;
    }
};
