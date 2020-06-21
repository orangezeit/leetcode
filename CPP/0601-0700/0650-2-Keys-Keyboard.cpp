class Solution {
public:
    int minSteps(int n) {
        int i = 2;
        int step = 0;
        while (i <= n) {
            while (n % i == 0) {
                n /= i;
                step += i;
            }
            i++;
        }
        return step;
    }
};
