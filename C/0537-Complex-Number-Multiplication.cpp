    string complexNumberMultiply(string a, string b) {
        vector<int> ai(2), bi(2);
        
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == '+') {
                ai[0] = stoi(a.substr(0, i));
                ai[1] = stoi(a.substr(i+1, a.length()-i-2));
                break;
            }
        }
        
        for (int i = 0; i < b.length(); ++i) {
            if (b[i] == '+') {
                bi[0] = stoi(b.substr(0, i));
                bi[1] = stoi(b.substr(i+1, b.length()-i-2));
                break;
            }
        }
        
        return to_string(ai[0] * bi[0] - ai[1] * bi[1]) + "+" + to_string(ai[0] * bi[1] + ai[1] * bi[0]) + "i";
    }
