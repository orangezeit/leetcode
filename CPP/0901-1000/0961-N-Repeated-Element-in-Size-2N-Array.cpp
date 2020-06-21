class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> ans;

        for (int i = 0; i < A.size(); ++i) {
            if (ans.find(A[i]) == ans.end())
                ans.insert(A[i]);
            else
                return A[i];
        }
        return -1;
    }
};
