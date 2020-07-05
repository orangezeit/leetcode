class Solution {
public:
    int minimumDistance(string word) {
        const int n(word.length());
        int mem[n][27] = {};

        function<int(int, int)> cost = [](const int& c1, const int& c2) {
            return c1 == 26 ? 0 : abs(c1 / 6 - c2 / 6) + abs(c1 % 6 - c2 % 6);
        };
        function<int(int, int)> dp = [&](int i, int o) {
            if (i == n) return 0;
            if (mem[i][o]) return mem[i][o];
            int p = i ? word[i - 1] - 'A' : 26;
            int c = word[i] - 'A';
            return mem[i][o] = min(dp(i + 1, o) + cost(p, c), dp(i + 1, p) + cost(o, c));
        };

        return dp(0, 26);
    }
};
