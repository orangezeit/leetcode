class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int lower_bound = A[0];
        int upper_bound = A[0];

        for (int i = 1; i < A.size(); ++i) {
            lower_bound = max(lower_bound, A[i]);
            upper_bound = min(upper_bound, A[i]);
        }

        return max(lower_bound - upper_bound - 2 * K, 0);
    }
};
