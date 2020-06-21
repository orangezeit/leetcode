class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        // O(n lg n)
        sort(A.rbegin(), A.rend());
        for (int i = 0; i < A.size() - 2; ++i)
            if (A[i+1] + A[i+2] > A[i])
                return A[i] + A[i+1] + A[i+2];
        return 0;
    }
};
