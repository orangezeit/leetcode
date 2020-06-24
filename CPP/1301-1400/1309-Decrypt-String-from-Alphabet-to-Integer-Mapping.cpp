class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        bool marked = false;
        for (int i = s.length() - 1; i >= 0; ) {
            if (s[i] == '#') {
                marked = true;
                i -= 1;
            } else if (marked) {
                ans += stoi(s.substr(i-1, 2)) + 'a' - 1;
                marked = false;
                i -= 2;
            } else {
                ans += stoi(s.substr(i, 1)) + 'a' - 1;
                i -= 1;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
