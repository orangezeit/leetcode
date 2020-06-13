class Solution {
public:
    bool confusingNumber(int N) {
        int nc(N);
        int cn(0);

        while (N) {
            cn *= 10;
            int temp = N % 10;

            if (temp == 0 || temp == 1 || temp == 8) {
                cn += temp;
            } else if (temp == 6 || temp == 9) {
                temp == 6 ? cn += 9 : cn += 6;
            } else {
                return false;
            }

            N /= 10;
        }

        return cn != nc;
    }
};
