    int firstBadVersion(int n) {
        int i = 1;
        int j = n;
        
        while (j-i > 1) {
            int m = i + (j-i) / 2;
            if(isBadVersion(m)) {
                j = m;
            } else {
                i = m;
            }
        }
        
        if (isBadVersion(i)) {
            return i;
        } else {
            return j;
        }
    }
