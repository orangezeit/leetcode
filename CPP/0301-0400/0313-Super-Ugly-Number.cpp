class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector <int> results (1,1);
        vector<int> factors(primes.size(), 0);
        while (results.size() < n)
        {
            int num = INT_MAX;
            for (int i = 0; i < factors.size(); ++i) {
                num = min(num, results[factors[i]] * primes[i]);
            }
            results.push_back(num);
            for (int i = 0; i < factors.size(); ++i) {
                if (num == results[factors[i]] * primes[i]) {
                    factors[i]++;
                }
            }
        }
        return results.back();
    }
};
