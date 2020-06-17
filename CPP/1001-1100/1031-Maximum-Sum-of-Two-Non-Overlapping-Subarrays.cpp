class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        // pre-sum
        for (int i = 0; i < A.size() - 1; ++i)
            A[i+1] += A[i];

        int s(0), temp;

        for (int i = L - 1; i < A.size(); ++i) {
            i == L - 1 ? temp = A[i] : temp = A[i] - A[i - L];

            for (int j = M - 1; j < i + 1 - L; ++j)
                j == M - 1 ? s = max(s, temp + A[j]) : s = max(s, temp + A[j] - A[j - M]);

            for (int j = i + M; j < A.size(); ++j)
                s = max(s, temp + A[j] - A[j - M]);
        }

        return s;
    }
};
