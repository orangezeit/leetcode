class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n(mat.size()), m(mat[0].size()), ans(0);
        vector<int> h(n), v(m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j]) {h[i]++; v[j]++;}

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mat[i][j] && h[i] == 1 && v[j] == 1) ans++;
        return ans;
    }
};

