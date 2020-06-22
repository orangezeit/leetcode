class Solution {
private:
    int gcd (int x, int y) {
        if (x == 0) {
            return y;
        } else {
            return gcd(y % x, x);
        }
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x == 0 && y == 0) {
            return z == 0;
        }

        if (z > x + y) {
            return false;
        }
        if (x > y) {
            swap(x, y);
        }

        return z % gcd(x, y) == 0;
    }
};
