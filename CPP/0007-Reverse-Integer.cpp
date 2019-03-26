    string str_reverse(string str) {
        for (int i = 0; i < str.length() / 2; ++i) {
            swap(str[i], str[str.length()-i-1]);
        }
        return str;
    }
    
    int reverse(int x) {
        string str = str_reverse(to_string(x));
        
        if (x < 0) {
            str.pop_back();
        }
        
        if (str.length() < 10 || str <= "2147483647") {
            if (x < 0) {
                return -stoi(str);
            }
            
            return stoi(str);
        }
        
        return 0;
    }
