    int findComplement(int num) {
        vector<int> binary(32, 0);
        int k(0), two(1), sum(0);
        
        while (num) {
            binary[k++] = num % 2;
            num /= 2;
        }
        
        for (int i = 0; i < k; ++i) {
            if (binary[i] - 1) sum += two;
            two *= 2;
        }
        
        return sum;
    }
