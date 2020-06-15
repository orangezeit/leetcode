class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> ans;
        int n(words.size());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (words[i].find(words[j]) != string::npos) {
                    ans.insert(words[j]);
                } else if (words[j].find(words[i]) != string::npos) {
                    ans.insert(words[i]);
                }
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};
