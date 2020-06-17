class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        for (int i = A.size() - 2; i >= 0; --i) {
            if (A[i] > A[i + 1]) {
                int lb(0), k(A.size() - 1);
                for (int j = A.size() - 1; j > i; --j) {
                    if (A[j] < A[i] && A[j] >= lb) {
                        lb = A[k = j];
                    }
                }
                swap(A[i], A[k]);
                return A;
            }
        }

        return A;
    }
};
