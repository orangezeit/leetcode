    void bin(int n, vector<int>& binary, int& s) {
        int k = 0;
        
        while (n >= 1) {
            binary[k++] = n % 2;
            n /= 2;
        }
        
        s = max(s, k);
    }
    
    int hammingDistance(int x, int y) {
        vector<int> bx(32, 0), by(32, 0);
        int s(0), dist(0);
        
        bin(x, bx, s);
        bin(y, by, s);
        
        for (int i = 0; i < s; ++i) {
            if (bx[i]-by[i]) {
                dist++;
            }
        }
        
        return dist;
    }
