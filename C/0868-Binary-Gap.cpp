    vector<int> fill(int N) {
        vector<int> ones;
        int i = 0;
        
        while (N) {
            if (N % 2) {
                ones.push_back(i);
            }
            N /= 2;
            i++;
        }
        
        return ones;
    }
    
    int binaryGap(int N) {
        vector<int> ones = fill(N);
        int gap = 0;
        
        for (int i = 0; i < ones.size() - 1; ++i) {
            gap = max(gap, ones[i+1] - ones[i]);
        }
        
        return gap;
    }
