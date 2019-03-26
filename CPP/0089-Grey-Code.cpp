    vector<int> grayCode(int n) {
        if (n == 0) {
            return vector<int>(1,0);
        }
        
        vector<int> twos(n,1);
        
        for (int i = 1; i < n; ++i) {
            twos[i] = 2 * twos[i-1];
        }
        
        vector<vector<int>> binary(2 * twos.back(), vector<int>(n));
        vector<int> nums(2 * twos.back());
        int c(0);
        
        for (int i = 0; i < n; ++i) {
            int j = 0;
            while (j < 2 * twos.back()) {
                if (j % (twos[i] * 2) == twos[i]) {
                    if (c) {
                        c = 0;
                    } else {
                        c = 1;
                    }
                }
                binary[j++][i] = c;
            }
        }
        
        for (int i = 0; i < 2 * twos.back(); ++i) {
            int num = 0;
            for (int j = 0; j < n; ++j) {
                num += twos[j] * binary[i][j];
            }
            nums[i] = num;
        }
        
        return nums;
    }
