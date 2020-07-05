class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> f1, f2;

        for (int i = 1; i * i <= n; ++i)
            if (n % i == 0) {
                f1.emplace_back(i);
                if (i != n / i)
                    f2.emplace_back(n / i);
            }

        f1.insert(f1.end(), f2.rbegin(), f2.rend());
        return k <= f1.size() ? f1[k - 1] : -1;
    }
};
