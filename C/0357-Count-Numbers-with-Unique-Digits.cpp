    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        
        n = min(n, 10);
        int sum(10), product(9), factor(9);
        
        while (n != 1) {
            product *= factor;
            sum += product;
            factor--;
            n--;
        }
        return sum;
    }
