class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int sa(0), sb(0), sa2(0), sb2(0);
        for (int i = 0; i < A.size() && (A[i] == A[0] || B[i] == A[0]);) {
            if (A[i] == A[0] && B[i] != A[0]) sb++;
            if (A[i] != A[0] && B[i] == A[0]) sa++;
            if (++i == A.size()) return min(sa, sb);
        }
        for (int i = 0; i < A.size() && (A[i] == B[0] || B[i] == B[0]);) {
            if (A[i] == B[0] && B[i] != B[0]) sb2++;
            if (A[i] != B[0] && B[i] == B[0]) sa2++;
            if (++i == A.size()) return min(sa2, sb2);
        }
        return -1;
    }
};
