    int hammingWeight(uint32_t n) {
        int h(0);
        
        while (n > 0) {
            if (n % 2 == 1) {
                h++;
            }
            n = n / 2;
        }
        
        return h;
    }
