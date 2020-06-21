class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> mc(m, vector<int>(n));

        int dirs[3] = {-1, 0, 1};

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int s(0), c(0);
                for (int x = 0; x < 3; ++x)
                    for (int y = 0; y < 3; ++y) {
                        int ni(i + dirs[x]), nj(j + dirs[y]);
                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                        s += mat[ni][nj];
                        c++;
                    }
                mc[i][j] = s / c;
            }

        return mc;
    }
};
