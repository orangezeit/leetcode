    int uniquePaths(int m, int n) {
        double factor = 1.0;
        
        for (int i = 1; i < min(m, n); ++i) {
            factor = factor / i * (i + max(m, n) - 1);
        }

        return int(factor);
    }
