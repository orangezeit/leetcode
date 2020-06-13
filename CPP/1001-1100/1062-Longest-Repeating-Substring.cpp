class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int result = 0;
        for (int i = 1; i < S.size(); ++i) {
            string temp = S.substr(0, S.size() - i);
            int tempMax = 0;
            for (int j = 0; j < temp.size(); ++j) {
                if (temp[j] == S[i + j]) ++tempMax;
                else tempMax = 0;
                result = max(tempMax, result);
            }
        }
        return result;
    }
};
