class Solution {
public:
    int countLetters(string S) {
        S += '*';
        int k = 0;
        int ans = 0;
        for (int i = 1; i < S.length(); ++i) {
            if (S[i] != S[i - 1]) {
                ans += (i - k + 1) * (i - k) / 2;
                k = i;
            }
        }

        return ans;
    }
};
