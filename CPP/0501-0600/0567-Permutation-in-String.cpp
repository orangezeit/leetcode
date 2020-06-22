class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        vector<int> letters(26);

        for (int i = 0; i < s1.length(); ++i) {
            letters[s1[i] - 'a']++;
            letters[s2[i] - 'a']--;
        }

        auto check = [&](){
            for (int i = 0; i < 26; ++i)
                if (letters[i])
                    return false;
            return true;
        };

        for (int i = s1.length(); i < s2.length(); ++i) {
            if (check()) return true;
            letters[s2[i] - 'a']--;
            letters[s2[i - s1.length()] - 'a']++;
        }

        return check();
    }
};
