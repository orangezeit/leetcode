class Solution {
public:
    bool compare(const string& s, const string& t) {
        if (s.length() >= t.length()) return true;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != t[i]) return true;
        }

        return t[s.length()] != '/';
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;

        for (const string& s: folder) {
            if (ans.empty() || compare(ans.back(), s))
                ans.push_back(s);
        }

        return ans;
    }
};
