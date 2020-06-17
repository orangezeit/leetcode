class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        for (int i = 1; i < A.size(); ++i) {
            A[i] += A[i-1];
        }

        if (A.back() % 3) return false;

        bool third = false;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] == A.back() / 3) third = true;
            if (A[i] == A.back() / 3 * 2 && third) return true;
        }

        return false;
    }
};
