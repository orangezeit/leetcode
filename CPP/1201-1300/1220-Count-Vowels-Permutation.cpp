class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long> v(5, 1);
        while (--n) {
            long na = (v[1] + v[2] + v[4]) % 1000000007;
            long ne = v[0] + v[2];
            long ni = v[1] + v[3];
            long no = v[2];
            long nu = v[2] + v[3];
            v[0] = na % 1000000007;
            v[1] = ne % 1000000007;
            v[2] = ni % 1000000007;
            v[3] = no % 1000000007;
            v[4] = nu % 1000000007;
        }

        int ans(0);
        for (const long& i : v) {
            ans += (i % 1000000007);
            ans %= 1000000007;
        }
        return ans;
    }
};
