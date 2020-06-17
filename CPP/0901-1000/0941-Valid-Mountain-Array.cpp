class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int i(0), j(A.size() - 1);
        while (i < j && A[i] < A[i+1]) i++;
        if (i == j) return false;
        while (i < j && A[j] < A[j-1]) j--;
        return i && i == j;
    }
};
