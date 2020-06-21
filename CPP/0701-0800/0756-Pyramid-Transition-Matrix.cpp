class Solution {
public:
    bool dfs(unordered_map<string, unordered_set<char>>& rec, string curr, string prev, int i) {
        if (curr.length() + 1 == prev.length())
            return curr.empty() ? true : dfs(rec, "", curr, 0);

        string str = prev.substr(i, 2);
        for (const char& c: rec[str])
            if (dfs(rec, curr + c, prev, i + 1))
                return true;

        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, unordered_set<char>> rec;
        string curr;

        for (string& str: allowed) {
            char c = str.back();
            str.pop_back();
            rec[str].insert(c);
        }

        return dfs(rec, curr, bottom, 0);
    }
};
