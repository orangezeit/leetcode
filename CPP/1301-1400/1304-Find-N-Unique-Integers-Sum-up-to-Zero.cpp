class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v(n);
        int s(0);
        for (int i = 0; i < n - 1; ++i) {
            v[i] = i;
            s += i;
        }
        v.back() = -s;
        return v;
    }
};
