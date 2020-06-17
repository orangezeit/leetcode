class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x(0), y(0), d(0), dirs[5] = {0, 1, 0, -1, 0};

        for (const char& c: instructions) {
            if (c == 'G') {
                x += dirs[d];
                y += dirs[d + 1];
            } else {
                d = (d + (c == 'R' ? 1 : 3)) % 4;
            }
        }

        return !x && !y || d;
    }
};
