class Solution {
public:

    int kthGrammar(int N, int K) {
        int digit = 0;
        int power = 1;

        while (--N > 1) power <<= 1;
        while (K > 1) {
            if (K > power) {
                K -= power;
                digit = 1 - digit;
            }
            power >>= 1;
        }

        return digit;
    }
};
