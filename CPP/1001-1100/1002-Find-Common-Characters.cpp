class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> counter(26, 100);

        for (const string& s: A) {
            vector<int> temp(26, 0);

            for (const char& c: s)
                temp[c - 'a']++;

            for (int j = 0; j < 26; ++j)
                counter[j] = min(counter[j], temp[j]);
        }

        vector<string> chars;

        for (int i = 0; i < 26; ++i) {
            vector<string> temp(counter[i], string(1, 'a' + i));
            chars.insert(chars.end(), temp.begin(), temp.end());
        }

        return chars;
    }
};
