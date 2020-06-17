class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        for (int i = 1; i < A.size(); ++i) {
            A[i] += A[i-1] * 2;
            A[i] %= 5;
        }

        vector<bool> ans(A.size());

        for (int i = 0; i < A.size(); ++i) {
            ans[i] = A[i] % 5 == 0;
        }

        return ans;
    }
};
