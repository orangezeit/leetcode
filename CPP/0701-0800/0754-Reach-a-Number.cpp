class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);

        int step = 0;
        int sum = 0;

        while (sum < target)
            sum += ++step;

        return (sum - target) % 2 ? step + 1 + (step % 2) : step;
    }
};
