class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size())
            return false;

        unordered_map<string, unordered_set<string>> dict;

        for (int i = 0; i < pairs.size(); ++i) {
            dict[pairs[i][0]].insert(pairs[i][1]);
            dict[pairs[i][1]].insert(pairs[i][0]);
        }

        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i])
                continue;
            if (dict[words1[i]].find(words2[i]) == dict[words1[i]].end())
                return false;
        }

        return true;
    }
};
