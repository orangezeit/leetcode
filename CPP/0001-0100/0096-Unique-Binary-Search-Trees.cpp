    double factorial(int a, int b) {
        if (a == b) {
            return double(a);
        } else {
            return b * factorial(a, b-1);
        }
    }
    
    int numTrees(int n) {
        return int(round(factorial(n + 1, 2 * n) / factorial(1, n+1)));
    }
