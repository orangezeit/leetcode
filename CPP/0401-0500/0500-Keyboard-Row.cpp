class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        const vector<string> keyboard = {"qwertyuiop", "asdfghjkl"};
        for(const string& w: words) {
            int flag(0);
            for (const char& c: w) {
                int line = keyboard[0].find(tolower(c)) != string::npos ? 0 :
                           keyboard[1].find(tolower(c)) != string::npos ? 1 : 2;
                flag |= (1 << line);
                if (flag & (flag - 1)) break;
            }
            if (!(flag & (flag - 1))) res.emplace_back(w);
        }
        return res;
    }
};
