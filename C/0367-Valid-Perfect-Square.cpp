    bool isPerfectSquare(int num) {
        int i = 0;
        int j = 46340;
        
        while (i <= j) {
            int m = (i+j)/2;
            if (num == m * m) {
                return true;
            } else if (num < m * m) {
                j = m-1;
            } else {
                i = m+1;
            }
        }
        
        return false;
    }
