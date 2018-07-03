    int integerReplacement(int n) {
        int c = 0;
        
        while (n != 1) {
            if (n == INT_MAX) {
                return 32;
            }
            
            if (n == 3) {
                return c+2;
            }
            
            if (n % 2 == 0) {
                n /= 2;
            } else if (n % 4 == 3) {
                ++n;
            } else {
                --n;
            }
            
            ++c;
        }
        
        return c;
    }
