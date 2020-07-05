class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int, int> rows;
        for (const vector<int>& r: rs) rows[r[0]] |= (1 << (r[1] - 1));
        int ans(2 * (n - rows.size()));

        for (const auto& [idx, row]: rows) {
            int s2 = (row & 0b0000011110) == 0;
            int s4 = (row & 0b0001111000) == 0;
            int s6 = (row & 0b0111100000) == 0;
            ans += max(s2 + s6, s4);
        }
        return ans;
    }
};
