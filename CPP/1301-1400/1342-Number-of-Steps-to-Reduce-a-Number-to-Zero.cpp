class Solution {
public:
    int numberOfSteps (int num) {
        int steps(0);
        while (num) {
            num % 2 ? num-- : num /= 2;
            steps++;
        }
        return steps;
    }
};
