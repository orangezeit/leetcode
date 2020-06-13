    bool isHappy(int n) {
        unordered_set<int> record;
        record.insert(n);
        
        while (n) {
            string str = to_string(n);
            n = 0;
            
            for (int i = 0; i < str.length(); ++i) {
                n += (str[i] - '0') * (str[i] - '0');
            }
            
            if (n == 1) {
                return true;
            } else if (record.find(n) != record.end()) {
                return false;
            } else {
                record.insert(n);
            }
        }
    }
