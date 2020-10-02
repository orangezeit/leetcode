class Solution {
public:
    bool isTransformable(string s, string t) {
        int rec[10] = {};
        for (int i = 0; i < s.length(); ++i) {
            rec[s[i] - '0']++;
            if (!(--rec[t[i] - '0'])) continue;
            for (int j = t[i] - '1'; j >= 0; --j)
                if (rec[j] > 0)
                    return false;
        }
        return true;
    }
};
