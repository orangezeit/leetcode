class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        // O(N)
        int res(0), pm[2]({-1, 1});

        for (const int& p: pm) {
            for (const int& q: pm) {
                int origin = p * arr1[0] + q * arr2[0];
                for (int i = 1; i < arr1.size(); ++i) {
                    int curr = p * arr1[i] + q * arr2[i] + i;
                    res = max(res, curr - origin);
                    origin = min(origin, curr);
                }
            }
        }

        return res;
    }
};
