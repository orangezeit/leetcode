class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string ans;

        for (const string& t: d) {
            int j(0), k(0);
            while(k < s.length() && j < t.length()) {
                if (s[k] == t[j]) j++;
                k++;
            }

            if (j == t.length())
                if (t.length() > ans.length() || t.length() == ans.length() && t < ans)
                    ans = t;
        }

        return ans;
    }
};
