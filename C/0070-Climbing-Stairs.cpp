    int climbStairs(int n) {
        // Fibonacci sequence
        
        int j(1), k(1);
        
        for (int i = 1; i <= n; ++i) {
            if (i % 2) {
                k += j;
            } else {
                j += k;
            }
        }
        
        if (n % 2) {
            return j;
        } else {
            return k;
        }
    }
