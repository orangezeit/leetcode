class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        set<int> prev;
        int sum(-1);
        for (int i = 0; i < A.size(); ++i) {
            for (auto it = prev.begin(); it != prev.end(); ++it) {
                if (*it + A[i] >= K) break;
                sum = max(sum, *it + A[i]);
            }
            prev.insert(A[i]);
        }
        return sum;
    }
};
