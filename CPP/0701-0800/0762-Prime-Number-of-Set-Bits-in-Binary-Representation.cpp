class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes = {2,3,5,7,11,13,17,19,23,29,31};

        int num, digit;
        int cnt = 0;

        for (int i = L; i <= R; ++i) {
            num = i;
            digit = 1;
            while (num != 1) {
                if (num % 2 == 1) {
                    digit++;
                }
                num /= 2;
            }

            if (primes.count(digit)) {
                cnt++;
            }
        }

        return cnt;
    }
};
