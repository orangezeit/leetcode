class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i = A.size() - 1;

        while (i) {

            A[i] += K % 10;
            A[i - 1] += (A[i] / 10);
            A[i--] %= 10;
            K /= 10;
        }

        while (K + A[0] > 9) {
            A.insert(A.begin(), 0);
            A[1] += K % 10;
            A[0] += (A[1] / 10);
            A[1] %= 10;
            K /= 10;
        }

        A[0] += K;
        return A;
    }
};
