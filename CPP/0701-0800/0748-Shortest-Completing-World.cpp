class Solution {
public:
    string shortestCompletingWord(string lp, vector<string>& words) {
        int license[26] = {}, word[26] = {};

        for (const char& c: lp)
            if (isalpha(c))
                license[tolower(c) - 'a']++;

        function<bool()> compare = [&]() {
            for (int i = 0; i < 26; ++i)
                if (license[i] > word[i])
                    return false;
            return true;
        };

        string ans(1001, ' ');

        for (const string& s: words) {
            for (const char& c: s)
                word[c - 'a']++;

            if (compare() && s.length() < ans.length())
                ans = s;
            fill(word, word + 26, 0);
        }

        return ans;
    }
};
