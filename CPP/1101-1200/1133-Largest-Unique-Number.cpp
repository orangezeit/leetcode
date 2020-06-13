class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        set<int> once, more;

        for (int i = 0; i < A.size(); ++i) {
            if (once.find(A[i]) == once.end() && more.find(A[i]) == more.end()) {
                once.insert(A[i]);
            } else if (once.find(A[i]) != once.end()) {
                once.erase(A[i]);
                more.insert(A[i]);
            }
        }

        return once.empty() ? -1 : *once.rbegin();
    }
};
