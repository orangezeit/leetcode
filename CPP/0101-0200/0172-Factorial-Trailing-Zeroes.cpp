    int trailingZeroes(int n) {
        int sum(0), five(5);
        
        while (n / five != 0) {
            sum += n / five;
            if (five < INT_MAX / 5) {
                five *= 5;
            } else {
                break;
            }
        }
        
        return sum;
    }
