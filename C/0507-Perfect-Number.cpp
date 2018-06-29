    bool checkPerfectNumber(int num) {
        int sum(1);
        
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                sum += (i + num / i);
            }
        }
        return num == sum && num != 1;
        
        // tricky method
        // return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
    }
