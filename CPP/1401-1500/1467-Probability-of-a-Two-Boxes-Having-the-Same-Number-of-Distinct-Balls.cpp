class Solution {
public:
    double getProbability(vector<int>& balls) {
        const int n = accumulate(balls.begin(), balls.end(), 0);
        const int k = balls.size();
        double total = 0.0;
        double valid = 0.0;
        vector<double> facts(26);
        facts[0] = facts[1] = 1.0;
        for (int i = 2; i <= 25; ++i) facts[i] = facts[i-1] * i;
        function<void(int, int, int, int, int, double, double)> dfs = [&](int d, int b1, int b2, int c1, int c2, double p1, double p2) {
            if (b1 > n / 2 || b2 > n / 2) return;
            if (d == k) {
                double cnt = facts[n / 2] / p1 * facts[n / 2] / p2;
                total += cnt;
                if (c1 == c2) valid += cnt;
                return;
            }
            for (int s1 = 0; s1 <= balls[d]; ++s1) {
                int s2 = balls[d] - s1;
                dfs(d + 1, b1 + s1, b2 + s2, c1 + (s1 > 0), c2 + (s2 > 0), p1 * facts[s1], p2 * facts[s2]);
            }
        };
        dfs(0, 0, 0, 0, 0, 1.0, 1.0);
        return valid / total;
    }
};
