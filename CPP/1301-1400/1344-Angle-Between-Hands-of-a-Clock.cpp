class Solution {
public:
    double angleClock(int h, int m) {
        double d = abs(h % 12 * 30 + m / 2.0 - m * 6);
        return min(d, 360 - d);
    }
};
