    string toGoatLatin(string S) {
        S += " ";
        int k(-1), c(1);
        string temp, str;
        
        for(int i = 1; i < S.length(); ++i) {
            if (S[i] == ' ') {
                temp = S.substr(k+1, i-k-1);
                if (temp[0] != 'a' && temp[0] != 'e' && temp[0] != 'i' && temp[0] != 'o' && temp[0] != 'u' && temp[0] != 'A' && temp[0] != 'E' && temp[0] != 'I' && temp[0] != 'O' && temp[0] != 'U') {
                    temp = temp.substr(1, temp.length()-1) + temp[0];
                }
                str += (temp + "ma" + string(c, 'a') + " ");
                k = i;
                c++;
            }
        }
        
        str.pop_back();
        return str;
    }
