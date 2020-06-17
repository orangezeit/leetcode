class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int sum(0);

        for (const int& a: A) sum += a;

        for (int i = 0; i < A.size(); ++i) {
            if (K && A[i] < 0) {
                K--;
                sum -= 2 * A[i];
            } else
                return K % 2 ? i && -A[i - 1] < A[i] ? sum + 2 * A[i - 1] : sum - 2 * A[i] : sum;
        }

        return -1;
    }
};
