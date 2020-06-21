class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        int i(1), j(n), m(0);
        while (i <= j)
            res[m++] = k > 1 && --k % 2 ? j-- : i++;

        return res;
    }
};
