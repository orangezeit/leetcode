class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m(dungeon.size()), n(dungeon[0].size());
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >=0; j--) {
                int a(i != m - 1 ? dungeon[i + 1][j] : -1), b(j != n - 1 ? dungeon[i][j + 1] : -1);
                int c(a == -1 && b == -1 ? 1 : a == -1 ? b : b == -1 ? a : min(a, b));
                dungeon[i][j] = max(c - dungeon[i][j], 1);
            }
        }

        return dungeon[0][0];
    }
};
