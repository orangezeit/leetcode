class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> record;
    bool inRange(const int& x, const int& y, const int& length, const int& width) {
        return x >= 0 && x < length && y >= 0 && y < width;
    }

    void travel(vector<vector<int>>& grid, int i, int j, const int& length, const int& width) {
        grid[i][j] = 2;
        record.back().push_back(i * width + j);

        for (int k = 0; k < 4; ++k)
            if (inRange(i + dir[k][0], j + dir[k][1], length, width))
                if (grid[i + dir[k][0]][j + dir[k][1]] == 1)
                    travel(grid, i + dir[k][0], j + dir[k][1], length, width);
    }

    bool verifyHelper(vector<int> prev, vector<int> curr) {
        for (int i = 0; i < prev.size() - 1; ++i) {
            if (curr[i] - prev[i] != curr[i+1] - prev[i+1])
                return false;
        }

        return true;
    }

    bool verify(vector<vector<int>> record) {
        for (int i = 0; i < record.size() - 1; ++i) {
            if(record[i].size() == record.back().size())
                if(verifyHelper(record[i], record.back()))
                    return false;
        }

        return true;
    }

public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int num = 0;
        int length = grid.size();

        if (length == 0)
            return 0;

        int width = grid[0].size();

        for (int i = 0; i < length; ++i)
            for (int j = 0; j < width; ++j)
                if (grid[i][j] == 1) {
                    record.push_back(vector<int>(0));
                    travel(grid, i, j, length, width);
                    if (verify(record))
                        num++;
                }

        return num;
    }
};
