class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n(A.size());
        vector<int> keeps(n, INT_MAX), swaps(n, INT_MAX);
        keeps[0] = 0;
        swaps[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (A[i - 1] < A[i] && B[i - 1] < B[i]) {
                keeps[i] = keeps[i - 1];
                swaps[i] = swaps[i - 1] + 1;
            }
            if (A[i - 1] < B[i] && B[i - 1] < A[i]) {
                keeps[i] = min(keeps[i], swaps[i - 1]);
                swaps[i] = min(swaps[i], keeps[i - 1] + 1);
            }
        }

        return min(keeps.back(), swaps.back());
    }
};
