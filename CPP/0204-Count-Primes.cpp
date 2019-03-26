    int countPrimes(int n) {   
        vector<bool> nums(n, true); // [0...(n-1)]
        int c(0);
        
        for (int i = 2; i * i < n; ++i) {
            if (nums[i]) {
                int j = i * i;
                while (j < n) {
                    nums[j] = false;
                    j += i;
                } 
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                c++;
            }
        }
        
        return max(0,c-2);
    }
