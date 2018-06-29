    bool alphanumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    
    bool isPalindrome(string s) {
        int i(0), j(s.length());
        
        while (i < j) {
            if (alphanumeric(s[i]) && alphanumeric(s[j])) {
                if (tolower(s[i++]) != tolower(s[j--])) {
                    return false;
                }
            } else {
                if (!alphanumeric(s[i])) {
                    i++;
                }
                
                if (!alphanumeric(s[j])) {
                    j--;
                }
            }
        }
        
        return true;
    }
