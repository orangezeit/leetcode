class Solution {
public:
    int numWaterBottles(int nb, int ne) {
        int s(nb), c(0);
        while (nb >= ne) {
            s += nb / ne;
            nb = nb / ne + nb % ne;
        }
        return s;
    }
};
