class Solution {
public:
    int l, w;

    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool check(int x, int y) {
        return x >= 0 && x < l && y >= 0 && y < w;
    }

    void floodFill(vector<vector<int>>& grid, int& k, vector<int>& counter) {

        bool forward = false;

        for (int i = 0; i < l; ++i)
            for (int j = 0; j < w; ++j)
                if (grid[i][j] == 2)
                    for (int n = 0; n < 4; ++n)
                        if (check(i + dir[n][0], j + dir[n][1]))
                            if (grid[i + dir[n][0]][j + dir[n][1]] == 1) {
                                if (!forward) forward = true;
                                grid[i + dir[n][0]][j + dir[n][1]] = 3;
                            }

        if (forward) {
            for (int i = 0; i < l; ++i)
                for (int j = 0; j < w; ++j)
                    if (grid[i][j] == 3) {
                        grid[i][j] = 2;
                        counter[2]++;
                        counter[1]--;
                    }
            k++;
            floodFill(grid, k, counter);
        } else {
            return;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        l = grid.size();
        w = grid[0].size();

        vector<int> counter(3, 0);

        for (int i = 0; i < l; ++i)
            for (int j = 0; j < w; ++j)
                counter[grid[i][j]]++;


        int k = 0;
        floodFill(grid, k, counter);

        return counter[1] ? -1 : k;
    }
};
