class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int r, int c, int r0, int c0) {
        map<int, vector<int>> record;

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                record[abs(i - r0) + abs(j - c0)].emplace_back(i * c + j);

        vector<vector<int>> ans(r * c, vector<int>(2));
        int k = 0;

        for (const auto& [d, ps]: record) {
            for (const int& p: ps) {
                ans[k][0] = p / c;
                ans[k][1] = p % c;
                k++;
            }
        }

        return ans;
    }
};
