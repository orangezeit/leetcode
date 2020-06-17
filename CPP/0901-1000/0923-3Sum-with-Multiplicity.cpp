class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        map<int, long> cnts;
        for (const int& i: A) cnts[i]++;
        long ans(0);
        for (const auto& [a1, c1]: cnts) {
            for (const auto& [a2, c2]: cnts) {
                if (a1 > a2) continue;
                int a3 = target - a1 - a2;
                if (!cnts.count(a3) || a2 > a3) continue;
                if (a1 == a2 && a2 == a3) {
                    ans += c1 * (c1 - 1) * (c1 - 2) / 6;
                } else if (a1 == a2) {
                    ans += c1 * (c1 - 1) / 2 * cnts[a3];
                } else if (a2 == a3) {
                    ans += c2 * (c2 - 1) / 2 * c1;
                } else {
                    ans += c1 * c2 * cnts[a3];
                }
                ans %= 1000000007;
            }
        }

        return ans % 1000000007;
    }
};
