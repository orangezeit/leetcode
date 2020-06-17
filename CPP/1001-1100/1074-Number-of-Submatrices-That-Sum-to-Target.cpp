class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m(matrix.size()), n(matrix[0].size()), ans(0);
        for (int i = 0; i < m; ++i) {
            vector<int> v(n);
            for (int j = i; j < m; ++j) {
                for (int k = 0; k < n; ++k)
                    v[k] += matrix[j][k];
                int ps(0);
                unordered_map<int, int> mp({{0, 1}});
                for (const int& s: v) {
                    ps += s;
                    if (mp.count(ps - target)) ans += mp[ps - target];
                    mp[ps]++;
                }
            }
        }
        return ans;
    }
};
