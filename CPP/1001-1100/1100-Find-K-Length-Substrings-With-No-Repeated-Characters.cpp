class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (S.length() < K) return 0;
        unordered_map<char, int> rec;
        int cnt(0);

        for (int i = 0; i < K; ++i) {
            rec[S[i]]++;
        }

        if (rec.size() == K) cnt++;

        for (int i = K; i < S.length(); ++i) {
            rec[S[i]]++;
            if (--rec[S[i-K]] == 0)
                rec.erase(S[i-K]);
            if (rec.size() == K) cnt++;
        }

        return cnt;
    }
};
