class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        vector<array<int, 4>> r = {{1,2,3,4}, {1,2,4,3}, {1,3,2,4}, {1,3,4,2}, {1,4,2,3}, {1,4,3,2},
                                 {2,1,3,4}, {2,1,4,3}, {2,3,1,4}, {2,3,4,1}, {2,4,1,3}, {2,4,3,1},
                                 {3,1,2,4}, {3,1,4,2}, {3,2,1,4}, {3,2,4,1}, {3,4,1,2}, {3,4,2,1},
                                 {4,1,2,3}, {4,1,3,2}, {4,2,1,3}, {4,2,3,1}, {4,3,1,2}, {4,3,2,1}};

        string ans;

        for (auto& [a, b, c, d]: r) {
            if (A[a-1] == 2 && A[b-1] > 3 || A[a-1] > 2 || A[c-1] >= 6)
                continue;
            string temp = to_string(A[a-1]) + to_string(A[b-1]) + ":" + to_string(A[c-1]) + to_string(A[d-1]);
            ans = max(ans, temp);
        }

        return ans;
    }
};
