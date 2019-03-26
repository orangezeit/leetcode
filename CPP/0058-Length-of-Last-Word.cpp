    int lengthOfLastWord(string s) {
        
        if (s.empty()) {
            return 0;
        }
        
        int i = s.length()-1;
        while (s[i] == ' ') {
            i--;
            if (i < 0) {
                return 0;
            }
        }

        int j = i;
        
        while (s[j] != ' ') {
            j--;
            if (j < 0) {
                break;
            }
        }
        
        return i-j;
    }
