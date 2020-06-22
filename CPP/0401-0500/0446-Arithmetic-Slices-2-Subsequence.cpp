class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<long, int>> rec(A.size());
        int ans(0);
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)A[i] - (long)A[j];
                rec[i][diff] += rec[j][diff] + 1;
                ans += rec[j][diff];
                //cout << rec[j][diff] << " " << diff << endl;
            }
        }

        return ans;
    }
};
