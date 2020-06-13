class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int maxSubSum(A[0]), maxTotal(A[0]), minSubSum(A[0]), minTotal(A[0]), s(A[0]);

        for (int i = 1; i < A.size(); ++i) {
            maxTotal = max(maxTotal, maxSubSum = max(A[i], maxSubSum + A[i]));
            minTotal = min(minTotal, minSubSum = min(A[i], minSubSum + A[i]));
            s += A[i];
        }

        return s == minTotal ? maxTotal : max(s - minTotal, maxTotal);
    }
};
