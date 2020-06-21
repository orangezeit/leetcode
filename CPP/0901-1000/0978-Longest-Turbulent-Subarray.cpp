class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n(A.size()), ans(1), s1(0), s2(0);
        for (int i = 0; i < n; i++) {
            bool b1 = (i ? A[i] < A[i - 1] : true) && (i < n - 1 ? A[i] < A[i + 1] : true);
            bool b2 = (i ? A[i] > A[i - 1] : true) && (i < n - 1 ? A[i] > A[i + 1] : true);

            if (i % 2) swap(b1, b2);
            if (b1) {
                s1++;
            } else if (s1) {
                ans = max(ans, s1 + (i - s1 > 0) + (i < n - 1));
                s1 = 0;
            }
            if (b2) {
                s2++;
            } else if (s2) {
                ans = max(ans, s2 + (i - s2 > 0) + (i < n - 1));
                s2 = 0;
            }
        }

        return min(max(ans, max(s1, s2) + 1), n);
    }
};
