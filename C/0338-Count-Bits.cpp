    int bitCount(int n) {
        int c = 0;
        
        while (n) {
            if (n % 2) {
                c++;
            }
            n /= 2;
        }
        
        return c;
    }
    
    vector<int> countBits(int num) {
        vector<int> bits(num+1);
        
        for(int i = 0; i <= num; ++i) {
            bits[i] = bitCount(i);
        }
        
        return bits;
    }
