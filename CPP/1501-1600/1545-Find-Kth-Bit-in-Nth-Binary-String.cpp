class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';
        if (k == 1 << (n - 1)) return '1';
        return k < 1 << (n - 1) ? findKthBit(n - 1, k) : '1' - findKthBit(n - 1, (1 << n) - k) + '0';
    }
};
