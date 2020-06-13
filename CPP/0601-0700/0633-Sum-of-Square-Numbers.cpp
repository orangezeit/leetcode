    bool judgeSquareSum(int c) {
        
        for (int i = 0; i <= sqrt(c/2); ++i) {
            if (abs(floor(sqrt(c-i*i)) - sqrt(c-i*i)) < numeric_limits<double>::epsilon()) {
                return true;
            }
        }
        
        return false;
    }
