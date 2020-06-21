class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        vector<bool> highs(A.size()), lows(A.size());
        highs[A.size() - 1] = lows[A.size() - 1] = true;

        map<int, int> rec;
        rec[A.back()] = A.size() - 1;
        int res(1);

        for (int i = A.size() - 2; i >= 0; --i) {
            auto hi = rec.lower_bound(A[i]), lo = rec.upper_bound(A[i]);
            if (hi != rec.end()) highs[i] = lows[hi->second];
            if (lo != rec.begin()) lows[i] = highs[(--lo)->second];
            if (highs[i]) res++;
            rec[A[i]] = i;
        }

        return res;
    }
};
