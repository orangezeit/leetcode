class Solution {
public:
    long trailingZeroes(long n) {
        long sum = 0;
        long five = 5;

        while (n / five != 0) {
            sum += n / five;
            five *= 5;
        }

        return sum;
    }

    int preimageSizeFZF(int K) {
        if (!K) return 5;
        long begin(1);

        while (trailingZeroes(begin) <= K) {
            begin *= 2;
        }
        long i = begin / 2;
        while (trailingZeroes(i) == K) {i /= 2;}
        long j = begin;

        //cout << i << " " << j << endl;
        while (j - i > 1) {
            long mid = (i + j) / 2;
            long cnt = trailingZeroes(mid);
            if (cnt < K) {
                i = mid;
            } else if (cnt > K) {
                j = mid;
            } else {
                break;
            }
            //cout << i << " " << j << endl;
        }

        while (trailingZeroes(i) < K) {i++;}
        while (trailingZeroes(j) > K) {j--;}
        //cout << i << " " << j << endl;
        return j - i + 1;
    }
};
