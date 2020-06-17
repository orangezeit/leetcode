class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> remainder(60, 0);
        int sum = 0;

        for (int i = 0; i < time.size(); ++i)
            remainder[time[i] % 60]++;

        for (int i = 1; i < 30; ++i)
            sum += remainder[i] * remainder[60-i];

        sum += remainder[0] * (remainder[0] - 1) / 2;
        sum += remainder[30] * (remainder[30] - 1) / 2;

        return sum;
    }
};
