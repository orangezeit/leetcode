    double myPow(double x, int n) {
        int k = 0;
        vector<int> bin(32, 0);
        vector<double> val(32, x);
        bool negative = n < 0;
        bool special = false;
        
        if (n == INT_MIN) {
            n = -INT_MAX;
            special = true;
        } else if (negative) {
            n = -n;
        }
        
        while (n) {
            bin[k++] = n % 2;
            n /= 2;
            if (k) {
                val[k] = val[k-1] * val[k-1];
            }
        }
        
        double product = 1.0;
        
        for (int i = 0; i < k; ++i) {
            if (bin[i]) {
                product *= val[i];
            }
        }
        
        if (special) {
            product *= x;
        }
        
        return negative ? 1 / product : product;
    }
