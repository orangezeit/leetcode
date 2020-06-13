class Solution {
public:
    // lg n
    int countDigits(int x, const int& d) {
        if (x == 0) return 0;
        if (x < 10 && d == 0) {
            return 0;
        }
        int res(0);
        int k(x % 10);
        if (x % 10 > d) res++;
        res += countDigits(x / 10, d) * 10;
        res += d ? x / 10 : x / 10 - 1;
        while (x /= 10) {
            res += (x % 10 == d) * k;
        }
        return res;
    }

    int digitsCount(int d, int low, int high) {
        //cout << countDigits(low, d) << endl;
        return countDigits(high + 1, d) - countDigits(low, d);
    }
};
