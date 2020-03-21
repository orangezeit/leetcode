class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> letters(26);

        for (const string& s: B) {
            vector<int> temp(26, 0);
            for (const char& c: s) temp[c - 'a']++;
            for (int j = 0; j < 26; ++j)
                letters[j] = max(letters[j], temp[j]);
        }

        vector<string> ans;

        for (const string& s: A) {
            vector<int> temp(26, 0);
            bool flag(true);

            for (const char& c: s) temp[c - 'a']++;
            for (int j = 0; j < 26; ++j)
                if (temp[j] < letters[j]) {
                    flag = false;
                    break;
                }

            if (flag) ans.push_back(s);
        }

        return ans;
    }
};
