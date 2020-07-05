class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int dx(0), dy(0);
        for (int i = 1; i < coordinates.size(); ++i) {
            int tx = coordinates[i][0] - coordinates[i - 1][0];
            int ty = coordinates[i][1] - coordinates[i - 1][1];

            if (tx * dy != ty * dx) {
                return false;
            } else if (!dx && !dy) {
                dx = tx;
                dy = ty;
           }
        }

        return true;
    }
};
