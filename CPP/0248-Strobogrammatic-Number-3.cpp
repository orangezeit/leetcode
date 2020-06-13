class Solution {
public:
    char c[5] = {'0', '1', '6', '8', '9'};
    char d[5] = {'0', '1', '9', '8', '6'};
    
    void helper(const int& n, int curr, string str, const string& bound, const bool flag, int& ans) {
        if (curr == n / 2) {
            if (n % 2) {
                for (int i = 0; i < 5; ++i) {
                    if (i == 2 || i == 4) continue;
                    str[curr] = c[i];
                    if (str < bound ^ flag || str == bound) ans++;
                }
            } else {
                if (str < bound ^ flag || str == bound) ans++;
            }
        } else {
            for (int i = (curr == 0); i < 5; ++i) {
                str[curr] = c[i];
                str[n - curr - 1] = d[i];
                helper(n, curr + 1, str, bound, flag, ans);
            }
        }
    }
    
    void helper2(const int& n, int curr, string str, const string& low, const string& high, int& ans) {
        if (curr == n / 2) {
            if (n % 2) {
                for (int i = 0; i < 5; ++i) {
                    if (i == 2 || i == 4) continue;
                    str[curr] = c[i];
                    if (str >= low && str <= high) ans++;
                }
            } else {
                if (str >= low && str <= high) ans++;
            }
        } else {
            for (int i = (curr == 0); i < 5; ++i) {
                str[curr] = c[i];
                str[n - curr - 1] = d[i];
                helper2(n, curr + 1, str, low, high, ans);
            }
        }
    }
    
    int strobogrammaticInRange(string low, string high) {
        int ans(0);
        int low_d(low.length()), high_d(high.length());
        
        if (low_d > high_d) return 0;
        if (low_d == high_d && low > high) return 0;
        
        for (int i = low_d + 1; i < high_d; ++i) {
            int n = 1;
            for (int k = (i - 1) / 2; k >= 0; --k)
                n *= i % 2 && k == i / 2 ? 3 : k == 0 ? 4 : 5;
            ans += n;
        }
        
        if (low_d == high_d) {
            helper2(low_d, 0, string(low_d, ' '), low, high, ans);
        } else {
            helper(low_d, 0, string(low_d, ' '), low, true, ans);
            helper(high_d, 0, string(high_d, ' '), high, false, ans);
        }
        
        return ans;
    }
};
