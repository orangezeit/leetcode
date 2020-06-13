    string convertToTitle(int n) {
        string str;
        
        while (n) {
            str += ('A' + (n-1)%26);
            n = (n-(n-1)%26)/26;
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
