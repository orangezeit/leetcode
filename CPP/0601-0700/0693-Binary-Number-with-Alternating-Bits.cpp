class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev(n % 2);

        while (n /= 2) {
            if (prev == n % 2)
                return false;
            prev = n % 2;
        }

        return true;
    }
};
