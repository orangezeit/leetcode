class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int rows, cols;
    bool check(int x, int y) {
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }


    void floodfill(vector<vector<int>>& A, int x, int y) {
        A[x][y] = 0;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dirs[i][0];
            int ny = y + dirs[i][1];

            if (check(nx, ny)) {
                if (A[nx][ny]) {
                    floodfill(A, nx, ny);
                }
            }
        }

    }

    int numEnclaves(vector<vector<int>>& A) {
        rows = A.size();
        cols = A[0].size();

        for (int i = 0; i < rows; ++i) {
            if (A[i][0]) floodfill(A, i, 0);
            if (A[i][cols - 1]) floodfill(A, i, cols - 1);
        }

        for (int i = 0; i < cols; ++i) {
            if (A[0][i]) floodfill(A, 0, i);
            if (A[rows - 1][i]) floodfill(A, rows - 1, i);
        }

        int num = 0;

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                num += A[i][j];

        return num;
    }
};
