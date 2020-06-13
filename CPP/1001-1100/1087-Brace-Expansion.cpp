class Solution {
public:
    void helper(vector<string>& letters, int i, string str, vector<string>& ans) {
        if (i == letters.size()) {
            ans.push_back(str);
        } else {
            sort(letters[i].begin(), letters[i].end());
            for (int j = 0; j < letters[i].length(); ++j)
                helper(letters, i+1, str+letters[i][j], ans);
        }
    }

    vector<string> expand(string S) {
        vector<string> letters;
        bool out = true;

        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '{')
                letters.push_back("");
            if (S[i] == '{' || S[i] == '}') {
                out = !out;
                continue;
            }
            if (out)
                letters.push_back("");

            if (S[i] >= 'a' && S[i] <= 'z')
                letters.back() += S[i];
        }

        vector<string> ans;
        helper(letters, 0, "", ans);

        return ans;
    }
};
