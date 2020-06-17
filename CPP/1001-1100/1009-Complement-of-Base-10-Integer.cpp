class Solution {
public:
    int bitwiseComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return num ? ~num ^ mask : 1;
    }
};
