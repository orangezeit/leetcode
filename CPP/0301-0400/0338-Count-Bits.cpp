class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n + 1);

        for(int i = 1; i <= n; ++i)
            bits[i] = i % 2 ? bits[i - 1] + 1 : bits[i / 2];

        return bits;
    }
};
