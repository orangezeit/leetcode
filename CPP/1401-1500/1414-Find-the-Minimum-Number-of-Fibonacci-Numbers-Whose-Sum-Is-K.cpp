class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> f({1, 1});
        while (f.back() <= k)
            f.push_back(f[f.size() - 2] + f[f.size() - 1]);
        f.pop_back();
        reverse(f.begin(), f.end());

        int ans(0);
        for (const int& i: f)
            if (i <= k) {
                k -= i;
                ans++;
            }
        return ans;
    }
};
