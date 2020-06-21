class Solution {
public:
    int brokenCalc(int X, int Y) {
        int t(0);

        while (Y > X) {
            Y % 2 ? Y++ : Y /= 2;
            t++;
        }

        return t + X - Y;
    }
};
