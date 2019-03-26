    uint32_t reverseBits(uint32_t n) {
        vector<int> bits(32, 0), binary(32, 1);
        
        for (int i = 1; i < 32; ++i) {
            binary[i] = 2 * binary[i-1];
        }
        
        int k(0), num(0);
        
        while (n >= 1) {
            bits[k++] = n % 2;
            n = n / 2;
        }
        
        for (int i = 0; i < k; ++i) {
            num += bits[i] * binary[31 - i];
        }
        
        return num;
    }
