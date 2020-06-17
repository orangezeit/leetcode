class Solution {
public:
    int clumsy(int N) {
        if (N == 1) return 1;
        if (N == 2) return 2;

        int f = N * (N - 1) / (N - 2) * 2;

        while (N / 4) {
            f -= N * (N - 1) / (N - 2) - (N - 3);
            N -= 4;
        }

        return N == 0 ? f : N == 1 ? f - 1 : N == 2 ? f - 2 : f - 6;
    }
};
