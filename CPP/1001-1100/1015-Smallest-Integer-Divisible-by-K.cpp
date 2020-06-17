class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if (K % 2 == 0 or K % 5 == 0) return -1;
        int s = 1;
        int base = 1;
        int n = 1;
        while (s % K) {
            base = (base * (10 % K)) % K;
            s += base;
            n++;
        }

        return n;
    }
};
