class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n(arr.size()), ans(0);
        int xors[n + 1]; xors[0] = 0;

        for (int i = 0; i < n; ++i)
            xors[i + 1] = xors[i] ^ arr[i];

        for (int i = 0; i < n; ++i)
            for (int k = i + 1; k < n; ++k)
                if (xors[i] == xors[k+1])
                    ans += k - i;
        return ans;
    }
};
