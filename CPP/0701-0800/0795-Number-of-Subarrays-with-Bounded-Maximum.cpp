class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int k = 0;
        int sum = 0;
        A.push_back(R + 1);
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] > R) {
                sum += (i - k + 1) * (i - k) / 2;
                int less(0);
                for (int j = k; j < i; ++j) {
                    if (A[j] < L) {
                        less++;
                    } else {
                        sum -= (less + 1) * less / 2;
                        less = 0;
                    }
                }
                sum -= (less + 1) * less / 2;
                k = i + 1;
            }
        }
        return sum;
    }
};
