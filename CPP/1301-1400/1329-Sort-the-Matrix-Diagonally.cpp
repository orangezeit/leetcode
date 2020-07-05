class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int m(mat.size()), n(mat[0].size());

        const auto modify = [&](int x, int y) {
            //int diag[min(m, n)] = {};
            vector<int> diag(min(m, n));
            int k(0);
            while (x < m && y < n)
            diag[k++] = mat[x++][y++];
            sort(diag, diag + k);
            while (x && y)
                mat[--x][--y] = diag[--k];
        };
        for (int i = 0; i < n; ++i) modify(0, i);
        for (int i = 1; i < m; ++i) modify(i, 0);
        return mat;
    }
};
