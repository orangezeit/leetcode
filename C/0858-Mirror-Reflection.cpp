    int mirrorReflection(int p, int q) {
        if (q == 0 || p == q) {
            return q / p;
        } else if (p % 2 == 1) {
            return q % 2;
        } else if (p % 4 == 0) {
            while (p % 2 == 0) {
                p /= 2;
            }
            
            if (p == 1) {
                return 2;
            } else {
                if (q % 8 == 0) {
                    return 0;
                } else if (q % 4 == 0) {
                    return 1;
                } else {
                    return 2;
                }
            }
            
        } else {
            if (q % 2 == 1) {
                return 2;
            } else if (q % 4 == 0) {
                return 0;
            } else {
                return 1;
            }
        }
    }
