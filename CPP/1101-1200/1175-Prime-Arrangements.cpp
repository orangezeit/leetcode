class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n + 1, true); // [0...(n-1)]
        int c(0);

        for (int i = 2; i * i <= n; ++i) {
            if (!nums[i]) continue;
            for (int j = i * i; j <= n; j += i)
                nums[j] = false;
        }
        //cout << "a";
        for (int i = 2; i <= n; ++i)
            if (nums[i]) c++;
        //cout << "b";
        return c;
    }

    int numPrimeArrangements(int n) {
        long ans(1);
        int p(countPrimes(n));
        //cout << p;
        for (int i = 1; i <= p; ++i) {
            ans *= i;
            ans %= (1000000007);
        }
        for (int i = 1; i <= n - p; ++i) {
            ans *= i;
            ans %= (1000000007);
        }
        return ans;
    }
};
