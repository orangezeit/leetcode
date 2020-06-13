    string toStr(long int num) {
        string digits = "0123456789abcdef";
        string str;
        
        while (num) {
            str += digits[num % 16];
            num /= 16;
        }
            
        reverse(str.begin(), str.end());
        return str;
    }
    
    string toHex(int num) {
        if (num > 0) {
            return toStr(num);
        } else if (num < 0) {
            return toStr(4294967296+num);
        } else {
            return "0";
        }
    }
