    string addBinary(string a, string b) {
        if (a.length() > b.length()) {
            a.swap(b);
        }
        
        b.insert(b.begin(), '0'); 
        
        for (int i = 0; i < b.length() - 1; ++i) {
            if (i < a.length()) {
                b[b.length()-i-1] += a[a.length()-i-1] - '0';
            }
            
            b[b.length()-i-2] += (b[b.length()-i-1] - '0') / 2;
            b[b.length()-i-1] = (b[b.length()-i-1] - '0') % 2 + '0';
        }
        
        if (b.front() == '0') {
            b.erase(b.begin());
        }
        
        return b;
    }
