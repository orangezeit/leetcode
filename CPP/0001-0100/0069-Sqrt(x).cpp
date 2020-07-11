class Solution {
public:
    int mySqrt(int x) {
        int i(0), j(46341);

        while (j - i > 1) {
            int m = (i + j) / 2;
            x < m * m ? j = m : i = m;
        }

        return i;
    }
};
