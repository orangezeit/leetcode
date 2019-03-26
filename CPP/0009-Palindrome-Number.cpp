    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string str = to_string(x);
        
        for (int i = 0; i < str.length() / 2; ++i) {
            if (str[i] != str[str.length()-i-1]) {
                return false;
            }
        }
        
        return true;
    }
