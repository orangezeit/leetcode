    int monotoneIncreasingDigits(int N) {
        string str = to_string(N);
        
        for (int i = 0; i < str.length() - 1; ++i) {
            if (str[i] > str[i+1]) {
                while (i >= 0) {
                    if (str[i] > str[i+1]) str[i--]--;
                    else break;
                }
                for (int j = i + 2; j < str.length(); ++j) str[j] = '9';
                break;
            }
        }
        
        return stoi(str);
    }
