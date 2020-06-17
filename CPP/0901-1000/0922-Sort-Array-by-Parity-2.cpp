class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i(0), j(1), n(A.size());
        while (i < n && j < n) {
            while (i < n && A[i] % 2 == 0) i += 2;
            while (j < n && A[j] % 2 == 1) j += 2;
            if (i >= n || j >= n) break;
            swap(A[i], A[j]);
            i += 2;
            j += 2;
        }
        return A;
    }
};
