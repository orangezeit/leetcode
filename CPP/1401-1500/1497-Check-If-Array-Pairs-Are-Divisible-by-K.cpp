class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> r(k);
        for (const int& i: arr)
            r[(i % k + k) % k]++;
        if (r[0] % 2) return false;
        for (int i = 1; i < k / 2; ++i)
            if (r[i] != r[k - i])
                return false;
        return k % 2 || r[k / 2] % 2 == 0;
    }
};
