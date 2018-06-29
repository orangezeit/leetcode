    int findComplement(int num) {
        if (num == 0) {
            return 1;
        }
        
        vector<int> binary(32, 0);
        
        int k(0), sum(0);
        
        while (num) {
            binary[k++] = num % 2;
            num /= 2;
        }
        
        vector<int> twos(k,1);
        
        for (int i = 1; i < k; ++i) {
            twos[i] = 2 * twos[i-1];
        }
        
        for (int i = 0; i < k; ++i) {
            if (binary[i] - 1) {
                sum += twos[i];
            }
        }
        
        return sum;
    }
