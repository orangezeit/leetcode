class Solution {
public:

    void buildDict(const vector<string>& words, unordered_map<int, unordered_set<int>>& dict, int index, int start, int end, bool& marked) {
        int k = start;
        bool remain = false;
        for (int i = start; i < end - 1; ++i)
            if (words[i].length() > index && words[i+1].length() > index) {
                remain = true;
                if (words[i][index] != words[i+1][index]) {
                    dict[words[i][index] - 'a'].insert(words[i+1][index] - 'a');
                    buildDict(words, dict, index + 1, k, i + 1, marked);
                    k = i + 1;
                }

            } else if (words[i].length() > index) {
                marked = true;
            }

        if (remain) buildDict(words, dict, index + 1, k, end, marked);
    }

    bool dfs(int curr, vector<int>& letters, string& res, unordered_map<int, unordered_set<int>>& dict) {
        if (letters[curr] == 1) return true;
        if (letters[curr] == 2) return false;
        letters[curr] = 2;
        for (const auto& it: dict[curr]) {
            if (!dfs(it, letters, res, dict)) return false;
        }
        letters[curr] = 1;
        res += curr + 'a';
        return true;
    }

    string alienOrder(vector<string>& words) {
        unordered_map<int, unordered_set<int>> dict;
        vector<int> letters(26, -1);
        for (int i = 0; i < words.size(); ++i)
            for (int j = 0; j < words[i].length(); ++j)
                letters[words[i][j] - 'a'] = 0;

        words.push_back("*");
        bool marked(false);
        buildDict(words, dict, 0, 0, words.size() - 1, marked);
        if (marked) return "";
        string res;

        for (int i = 0; i < 26; ++i)
            if (!letters[i] && !dfs(i, letters, res, dict)) return "";

        return string(res.rbegin(), res.rend());
    }
};
