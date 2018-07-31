vector<int> selfDividingNumbers(int left, int right) {
        vector<int> sd;
        
        for (int i = left; i <= right; ++i) {
            string str = to_string(i);
            bool d = true;
            
            for (int j = 0; j < str.length(); ++j) {
                if (str[j] == '0') {
                    d = false;
                    break;
                }
                
                if (i % (str[j] - '0')) {
                    d = false;
                    break;
                }
            }
            
            if (d) sd.push_back(i);
        }
        
        return sd;
    }
