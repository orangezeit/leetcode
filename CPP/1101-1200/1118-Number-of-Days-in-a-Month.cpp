class Solution {
public:
    int numberOfDays(int Y, int M) {
        return M == 2 ? Y % 400 ? Y % 100 ? Y % 4 ? 28 : 29 : 28 : 29 : M == 4 || M == 6 || M == 9 || M == 11 ? 30 : 31;
    }
};
