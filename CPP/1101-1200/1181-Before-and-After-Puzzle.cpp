class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, unordered_set<string>> forewords;
        unordered_map<string, int> unis;

        for (const string& s: phrases) {
            int i = -1;
            while (++i < s.length() && s[i] != ' ') {}
            unis[s]++;
            forewords[s.substr(0, i)].insert(s.substr(i, s.length() - i));
        }

        set<string> ans;

        for (const string& s: phrases) {
            int i = s.length();
            while (--i >= 0 && s[i] != ' ') {}
            string key = s.substr(i + 1, s.length() - i - 1);

            if (forewords.find(key) != forewords.end())
                for (const auto& str: forewords[key]) {
                    if (s == key + str && unis[s] <= 1) {
                        i = -1;
                        while (++i < s.length() && s[i] != ' ') {}
                        if (s.substr(0, i) == key) continue;
                    }

                    ans.insert(s + str);
                }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};
