    int guessNumber(int n) {
        int i = 1;
        int j = n;
        
        while (i <= j) {
            int m = j + (i-j)/2;
            if (guess(m) == 1) {
                i = m+1;
            } else if (guess(m) == -1) {
                j = m-1;
            } else {
                return m;
            }
        }
    }
