class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        set<int> num;
        unordered_set<string> record;
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); ++i) {
            num.insert(words[i].length());
            record.insert(words[i]);
        }

        for (int i = 0; i < text.length(); ++i) {
            for (auto it = num.begin(); it != num.end(); ++it) {
                if (i + *it <= text.length()) {
                    if (record.find(text.substr(i, *it)) != record.end()) {
                        ans.push_back({i, i + *it - 1});
                    }
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};
