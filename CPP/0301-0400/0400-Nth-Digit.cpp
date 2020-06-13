    int findNthDigit(int n) {
        int nine(9), ten(1), l(1);
        
        while (n > nine * l) {
            n -= nine * l;
            nine *= 10;
            ten *= 10;
            l++;
            if (l > INT_MAX / nine) {
                break;
            }
        }
        
        return to_string(ten + (n-1) / l)[(n-1) % l] - '0';
    }
