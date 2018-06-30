    int arrangeCoins(int n) {
        int i(0), j(65536), m, sum;
        
        while (j - i > 1) {
            m = (i+j)/2;
            
            if (m % 2) {
                sum = (m+1)/2*m;
            } else {
                sum = m/2*(m+1);
            }
            
            if (n < sum) {
                j = m;
            } else {
                i = m;
            }
        }

        return i;
    }
