class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
        int x(a.size()), y(b.size()), z(b[0].size());
        vector<vector<int>> c(x, vector<int>(z));
        unordered_map<int, int> ma, mb;
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < y; ++j)
                if (a[i][j])
                    ma[i * y + j] = a[i][j];
        for (int i = 0; i < y; ++i)
            for (int j = 0; j < z; ++j)
                if (b[i][j])
                    mb[i * z + j] = b[i][j];
        for (const auto&[k1, v1]: ma)
            for (const auto&[k2, v2]: mb)
                if (k1 % y == k2 / z)
                    c[k1 / y][k2 % z] += v1 * v2;
        return c;
    }
};
