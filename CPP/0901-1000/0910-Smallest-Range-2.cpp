class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        K *= 2;
        int mx(A.back()), mn(A[0]), res(A.back() - A[0]);
        // add 0 or K;
        for (int i = 0; i < A.size() - 1; ++i) {
            // if we do nothing, the res remains the same
            // if we add K, max will be max(mx, A[i] + K), and min will be (A[0] + K)
            res = min(res, max(mx, A[i] + K) - min(A[0] + K, A[i + 1]));
        }

        return res;
    }
};
