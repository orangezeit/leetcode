    string cs(string str) {
        str += " ";
        string newStr;
        int c(-1);
        
        for (int i = 0; i < str.length()-1; ++i) {
            if (str[i] != str[i+1]) {
                newStr += (to_string(i-c) + str[i]);
                c = i;
            }
        }
        
        return newStr;
    }
    
    string countAndSay(int n) {
        string str = "1";
        
        for (int i = 1; i < n; ++i) {
            str = cs(str);
        }
            
        return str;
        
    }
