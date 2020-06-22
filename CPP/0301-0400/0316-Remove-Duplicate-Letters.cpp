class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnts(26);
        vector<int> used(26, false);
        string ans;

        for (const char& c: s)
            cnts[c - 'a']++;

        for (const char& c: s) {
            if (!used[c - 'a']) {
                while (!ans.empty() && ans.back() > c && cnts[ans.back() - 'a']) {
                    used[ans.back() - 'a'] = false;
                    ans.pop_back();
                }

                ans += c;
                used[c - 'a'] = true;
            }
            cnts[c - 'a']--;
        }

        return ans;
    }
};
