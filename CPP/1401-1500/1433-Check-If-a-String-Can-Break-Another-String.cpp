class Solution {
public:
    bool canBreak(const int v[], bool flip=false) {
        int s(0);
        for (int i = 0; i < 25; ++i) {
            flip ? s -= v[i] : s += v[i];
            if (s < 0) return false;
        }
        return true;
    }
    bool checkIfCanBreak(const string& s1, const string& s2) {
        int letters[26] = {};
        for (const char& c: s1) letters[c - 'a']++;
        for (const char& c: s2) letters[c - 'a']--;
        return canBreak(letters) || canBreak(letters, true);
    }
};
