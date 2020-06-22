class Solution {
public:
    bool canConcatenate(string word, unordered_set<string>& s) {
        if (s.empty()) return false;
        bool dp[word.length() + 1] = {};

        dp[0] = true;
        for (int i = 1; i <= word.length(); ++i) {
            for (int j = 0; j < i; ++j) {

                if (!dp[j]) continue;
                if (s.count(word.substr(j,i-j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[word.length()];
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s1, const string& s2){return s1.length() < s2.length();});
        unordered_set<string> s;
        vector<string> ans;
        for (const string& word: words) {
            if (canConcatenate(word, s)) ans.push_back(word);
            s.insert(word);
        }
        return ans;
    }
};
