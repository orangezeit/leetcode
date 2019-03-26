    bool isPowerOfTwo(int n) {
        // Method 1: Bit Manipulation
        return !(n & (n-1)) && n > 0;
        
        // Method 2: Recursion
        if (n <= 0) {
            return false;
        }
        
        while (n) {
            if (n % 2) {
                return false;
            } else {
                n /= 2;
            }
        }
        
        return true;
    }
