class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod(1000000007), ans(0), c(0);
        bool odd(false);
        for (int i = 0; i < arr.size(); ++i) {
            ans += (odd ^= arr[i] % 2) ? (i + 1 - c++) : c;
            ans %= mod;
        }
        return ans;
    }
};
