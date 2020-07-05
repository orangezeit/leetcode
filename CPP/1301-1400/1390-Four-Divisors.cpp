class Solution {
public:
    const vector<int> find_primes(int n) {
        vector<bool> nums(n + 1);
        vector<int> ps;
        for (int i = 2; i <= n; ++i) {
            if (!nums[i]) ps.emplace_back(i);
            for (int j = 0; j < ps.size() && ps[j] * i <= n; ++j) {
                nums[i * ps[j]] = true;
                if (i % ps[j] == 0) break;
            }
        }
        return ps;
    }
    int sumFourDivisors(vector<int>& nums) {
        vector<int> ps = find_primes(*max_element(nums.begin(), nums.end()));
        int ans(0);
        for (const int& n: nums) {
            for (int i = 2; i * i < n; ++i) {
                if (n % i) continue;
                auto it = lower_bound(ps.begin(), ps.end(), i);
                if (it == ps.end() || *it != i) continue;
                if (i * i * i != n) {
                    auto jt = lower_bound(ps.begin(), ps.end(), n / i);
                    if (jt == ps.end() || *jt != n / i) continue;
                }
                ans += 1 + i + n / i + n;
                break;
            }
        }
        return ans;
    }
};
