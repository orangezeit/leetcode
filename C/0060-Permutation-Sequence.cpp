    string getPermutation(int n, int k) {
        k--;
        int factor = 1;
        vector<char> digits(n);
        string str;
        
        for (int i = 0; i < n; ++i) {
            digits[i] = i+'1';
            factor *= (i+1);
        }
        
        while (!digits.empty()) {
            factor /= n;
            n--;
            str += digits[k / factor];
            digits.erase(digits.begin()+ k/factor);
            k %= factor;
        }
        
        return str;
    }
