class Solution {
public:
    int rotatedDigits(int N) {
        int counts[10000];
        int different[10] = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
        int banned[10] = {0, 0, 0, 1, 1, 0, 0, 1, 0, 0};

        counts[0] = 0;

        for (int i = 1; i < 10000; ++i) {
            bool flag = true;
            bool unique = false;
            int num = i+1;

            while (num) {
                if (banned[num % 10]) {
                    flag = false;
                    break;
                } else if (different[num % 10]) {
                    unique = true;
                }
                num /= 10;
            }

            if (flag && unique) {
                counts[i] = counts[i-1] + 1;
            } else {
                counts[i] = counts[i-1];
            }
        }

        return counts[N-1];
    }
};
