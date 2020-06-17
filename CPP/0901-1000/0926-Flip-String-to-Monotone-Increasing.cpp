class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int zeros(0), ones(0), diff(0);

        for (int i = 0; i < S.length(); ++i) {
            S[i] == '0' ? zeros++ : ones++;
            diff = min(diff, ones - zeros);
        }

        return zeros + diff;
    }
};
