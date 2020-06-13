class Solution {
private:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool inRange(const int& x, const int& y, const int& length, const int& width) {
        return x >= 0 && x < length && y >= 0 && y < width;
    }

    void travel(vector<vector<int>>& rooms, int i, int j, int dist, int length, int width) {
        rooms[i][j] = min(rooms[i][j], dist);

        for (int k = 0; k < 4; ++k)
            if (inRange(i + dir[k][0], j + dir[k][1], length, width))
                if (rooms[i + dir[k][0]][j + dir[k][1]] > rooms[i][j])
                    travel(rooms, i + dir[k][0], j + dir[k][1], dist + 1, length, width);
    }

public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int length = rooms.size();

        if (length == 0)
            return;

        int width = rooms[0].size();

        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                if (rooms[i][j] == 0)
                    travel(rooms, i, j, 0, length, width);
            }
        }
    }
};
