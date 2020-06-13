class Solution {
public:
    string removeVowels(string S) {
        int k(0);
        for (int i = 0; i + k < S.length(); ++i) {
            while(S[i+k] == 'a' || S[i+k] == 'e' || S[i+k] == 'i' || S[i+k] == 'o' || S[i+k] == 'u') {
                k++;
                if (i + k == S.length())
                    return S.substr(0, i);
            }

            S[i] = S[i+k];
        }

        return S.substr(0, S.length() - k);
    }
};
