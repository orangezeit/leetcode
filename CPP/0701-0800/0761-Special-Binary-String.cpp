class Solution {
public:
    string specialHelper(const string& s, int begin, int end) {
        int c(0), i(begin);
        vector<string> res;

        for (int j = begin; j < end; ++j) {
            s[j] == '1' ? c++ : c--;
            if (c == 0) {
                res.push_back('1' + specialHelper(s, i + 1, j) + '0');
                i = j + 1;
            }
        }

        sort(res.rbegin(), res.rend());
        string ans;
        for (const string& str: res) ans += str;
        return ans;
    }

    string makeLargestSpecial(string s) {
        return specialHelper(s, 0, s.length());
    }
};
